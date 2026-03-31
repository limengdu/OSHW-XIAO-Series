/**
 * Written by Thomas Roth - code@stacksmashing.net
 *
 * Licensed under GPLv3
 *
 * Based on the spi_flash pico-example, which is:
 *  Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Also based on stm32-vserprog:
 *  https://github.com/dword1511/stm32-vserprog
 *
 * Adapted for Seeed Studio XIAO RP2040.
 * Pin connections (XIAO RP2040 -> SPI Flash):
 *   D7  (GPIO1)  -> CS#
 *   D8  (GPIO2)  -> SCK
 *   D10 (GPIO3)  -> MOSI
 *   D9  (GPIO4)  -> MISO
 *   D17 (GPIO17) -> User LED (activity indicator)
 */

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/clocks.h"
#include "pio/pio_spi.h"
#include "spi.h"

/* Seeed Studio XIAO RP2040 pin definitions
 * Verified against TinyGo machine definition for XIAO RP2040:
 *   SPI0_SCK=D8=GPIO2, SPI0_SDO=D10=GPIO3, SPI0_SDI=D9=GPIO4
 *   LED=GPIO17, LED_GREEN=GPIO16, LED_BLUE=GPIO25
 * Seeed wiki: D7=GPIO1 (RX, CSn)
 */
#define PIN_LED   17   /* D17 - USER_LED_R (red), activity indicator */
#define PIN_MISO   4   /* D9  - SPI0 SDI  */
#define PIN_MOSI   3   /* D10 - SPI0 SDO  */
#define PIN_SCK    2   /* D8  - SPI0 SCK  */
#define PIN_CS     1   /* D7  - CS# (shared with UART RX, but UART not used) */

#define BUS_SPI         (1 << 3)
#define S_SUPPORTED_BUS   BUS_SPI
#define S_CMD_MAP ( \
  (1 << S_CMD_NOP)       | \
  (1 << S_CMD_Q_IFACE)   | \
  (1 << S_CMD_Q_CMDMAP)  | \
  (1 << S_CMD_Q_PGMNAME) | \
  (1 << S_CMD_Q_SERBUF)  | \
  (1 << S_CMD_Q_BUSTYPE) | \
  (1 << S_CMD_SYNCNOP)   | \
  (1 << S_CMD_O_SPIOP)   | \
  (1 << S_CMD_S_BUSTYPE) | \
  (1 << S_CMD_S_SPI_FREQ)| \
  (1 << S_CMD_S_PIN_STATE) \
)

static uint32_t serprog_spi_init(uint32_t freq);

static inline void cs_select(uint cs_pin) {
    asm volatile("nop \n nop \n nop"); // FIXME
    gpio_put(cs_pin, 0);
    asm volatile("nop \n nop \n nop"); // FIXME
}

static inline void cs_deselect(uint cs_pin) {
    asm volatile("nop \n nop \n nop"); // FIXME
    gpio_put(cs_pin, 1);
    asm volatile("nop \n nop \n nop"); // FIXME
}

uint32_t getu24() {
    uint32_t c1 = getchar();
    uint32_t c2 = getchar();
    uint32_t c3 = getchar();
    return c1 | (c2<<8) | (c3<<16);
}

uint32_t getu32() {
    uint32_t c1 = getchar();
    uint32_t c2 = getchar();
    uint32_t c3 = getchar();
    uint32_t c4 = getchar();
    return c1 | (c2<<8) | (c3<<16) | (c4<<24);
}

void putu32(uint32_t d) {
    char buf[4];
    memcpy(buf, &d, 4);
    putchar(buf[0]);
    putchar(buf[1]);
    putchar(buf[2]);
    putchar(buf[3]);
}

unsigned char write_buffer[4096];

void process(const pio_spi_inst_t *spi, int command) {
    switch(command) {
        case S_CMD_NOP:
            putchar(S_ACK);
            break;
        case S_CMD_Q_IFACE:
            putchar(S_ACK);
            putchar(0x01);
            putchar(0x00);
            break;
        case S_CMD_Q_CMDMAP:
            putchar(S_ACK);
            putu32(S_CMD_MAP);

            for(int i = 0; i < 32 - sizeof(uint32_t); i++) {
                putchar(0);
            }
            break;
        case S_CMD_Q_PGMNAME:
            putchar(S_ACK);
            fwrite("pico-serprog\x0\x0\x0\x0\x0", 1, 16, stdout);
            fflush(stdout);
            break;
        case S_CMD_Q_SERBUF:
            putchar(S_ACK);
            putchar(0xFF);
            putchar(0xFF);
            break;
        case S_CMD_Q_BUSTYPE:
            putchar(S_ACK);
            putchar(S_SUPPORTED_BUS);
            break;
        case S_CMD_SYNCNOP:
            putchar(S_NAK);
            putchar(S_ACK);
            break;
        case S_CMD_S_BUSTYPE:
            {
                int bustype = getchar();
                if((bustype | S_SUPPORTED_BUS) == S_SUPPORTED_BUS) {
                    putchar(S_ACK);
                } else {
                    putchar(S_NAK);
                }
            }
            break;
        case S_CMD_O_SPIOP:
            {
                uint32_t wlen = getu24();
                uint32_t rlen = getu24();

                cs_select(PIN_CS);
                fread(write_buffer, 1, wlen, stdin);
                pio_spi_write8_blocking(spi, write_buffer, wlen);

                putchar(S_ACK);
                uint32_t chunk;
                char buf[128];

                for(uint32_t i = 0; i < rlen; i += chunk) {
                    chunk = MIN(rlen - i, sizeof(buf));
                    pio_spi_read8_blocking(spi, buf, chunk);
                    fwrite(buf, 1, chunk, stdout);
                    fflush(stdout);
                }

                cs_deselect(PIN_CS);
            }
            break;
        case S_CMD_S_SPI_FREQ:
            {
                uint32_t freq = getu32();
                if (freq >= 1) {
                    putchar(S_ACK);
                    putu32(serprog_spi_init(freq));
                } else {
                    putchar(S_NAK);
                }
            }
            break;
        case S_CMD_S_PIN_STATE:
            //TODO:
            getchar();
            putchar(S_ACK);
            break;
        default:
            putchar(S_NAK);
    }
}

// We use PIO 1 (same as original pico-serprog)
static const pio_spi_inst_t spi = {
    .pio = pio1,
    .sm = 0,
    .cs_pin = PIN_CS
};
static uint spi_offset;

static inline float freq_to_clkdiv(uint32_t freq) {
    float div = clock_get_hz(clk_sys) * 1.0 / (freq * pio_spi_cycles_per_bit);

    if (div < 1.0)
        div = 1.0;
    if (div > 65536.0)
        div = 65536.0;

    return div;
}

static inline uint32_t clkdiv_to_freq(float div) {
    return clock_get_hz(clk_sys) / (div * pio_spi_cycles_per_bit);
}

static uint32_t serprog_spi_init(uint32_t freq) {

    float clkdiv = freq_to_clkdiv(freq);

    pio_spi_init(spi.pio, spi.sm, spi_offset,
                 8,       // 8 bits per SPI frame
                 clkdiv,
                 false,   // CPHA = 0
                 false,   // CPOL = 0
                 PIN_SCK,
                 PIN_MOSI,
                 PIN_MISO);

    return clkdiv_to_freq(clkdiv);
}

int main() {
    // Metadata for picotool / binary info
    bi_decl(bi_program_description("Flashrom/serprog compatible firmware for Seeed Studio XIAO RP2040"));
    bi_decl(bi_program_url("https://github.com/Seeed-Studio/OSHW-XIAO-Series"));
    bi_decl(bi_1pin_with_name(PIN_LED,  "LED (activity indicator)"));
    bi_decl(bi_1pin_with_name(PIN_MISO,  "MISO"));
    bi_decl(bi_1pin_with_name(PIN_MOSI,  "MOSI"));
    bi_decl(bi_1pin_with_name(PIN_SCK,   "SCK"));
    bi_decl(bi_1pin_with_name(PIN_CS,    "CS#"));

    stdio_init_all();

    stdio_set_translate_crlf(&stdio_usb, false);

    // Initialize CS pin
    gpio_init(PIN_CS);
    gpio_put(PIN_CS, 1);
    gpio_set_dir(PIN_CS, GPIO_OUT);

    spi_offset = pio_add_program(spi.pio, &spi_cpha0_program);
    serprog_spi_init(1000000); // 1 MHz

    // Initialize LED
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    // Command handling loop
    while(1) {
        int command = getchar();

        gpio_put(PIN_LED, 1);
        process(&spi, command);
        gpio_put(PIN_LED, 0);
    }

    return 0;
}

/* According to Serial Flasher Protocol Specification - version 1 */
#define S_ACK 0x06
#define S_NAK 0x15
#define S_CMD_NOP		0x00	/* No operation					*/
#define S_CMD_Q_IFACE		0x01	/* Query interface version			*/
#define S_CMD_Q_CMDMAP		0x02	/* Query supported commands bitmap		*/
#define S_CMD_Q_PGMNAME		0x03	/* Query programmer name			*/
#define S_CMD_Q_SERBUF		0x04	/* Query Serial Buffer Size			*/
#define S_CMD_Q_BUSTYPE		0x05	/* Query supported bustypes			*/
#define S_CMD_Q_CHIPSIZE	0x06	/* Query supported chipsize (2^n format)	*/
#define S_CMD_Q_OPBUF		0x07	/* Query operation buffer size			*/
#define S_CMD_Q_WRNMAXLEN	0x08	/* Query Write to opbuf: Write-N maximum length */
#define S_CMD_R_BYTE		0x09	/* Read a single byte				*/
#define S_CMD_R_NBYTES		0x0A	/* Read n bytes					*/
#define S_CMD_O_INIT		0x0B	/* Initialize operation buffer			*/
#define S_CMD_O_WRITEB		0x0C	/* Write opbuf: Write byte with address		*/
#define S_CMD_O_WRITEN		0x0D	/* Write to opbuf: Write-N			*/
#define S_CMD_O_DELAY		0x0E	/* Write opbuf: udelay				*/
#define S_CMD_O_EXEC		0x0F	/* Execute operation buffer			*/
#define S_CMD_SYNCNOP		0x10	/* Special no-operation that returns NAK+ACK	*/
#define S_CMD_Q_RDNMAXLEN	0x11	/* Query read-n maximum length			*/
#define S_CMD_S_BUSTYPE		0x12	/* Set used bustype(s).				*/
#define S_CMD_O_SPIOP		0x13	/* Perform SPI operation.			*/
#define S_CMD_S_SPI_FREQ	0x14	/* Set SPI clock frequency			*/
#define S_CMD_S_PIN_STATE	0x15	/* Enable/disable output drivers		*/
