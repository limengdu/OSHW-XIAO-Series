# XIAO_ESP32C3_AI_Assistant

<div align="center">
<img src="pics/lobster_xiao_cropped_left.png" alt="zclaw on XIAO ESP32-C3" height="200">
<br/><br/>

[![ESP-IDF](https://img.shields.io/badge/ESP--IDF-ESP--IDF-green?style=flat&logo=espressif)](https://docs.espressif.com/projects/esp-idf/)
[![ESP32](https://img.shields.io/badge/ESP32-XIAO_ESP32C3-ED7B28?style=flat&logo=seeed)](https://www.seeedstudio.com/xiao-series-page)
[![C](https://img.shields.io/badge/C-C-A8B9CC?style=flat&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![AI](https://img.shields.io/badge/AI-LLM_Assistant-FF6B6B?style=flat&logo=openai)](https://openai.com/)
</div>

## Creator: [tnm](https://github.com/tnm)

We sincerely thank the original author and contributors of [**zclaw**](https://github.com/tnm/zclaw) for their open-source work, which forms the foundation of this project.

## Project Description
A minimal AI personal assistant running on Seeed Studio XIAO ESP32-C3, written in C with a strict all-in firmware budget of **≤ 888 KiB** (including ESP-IDF/FreeRTOS runtime, Wi-Fi, TLS, and cert bundle). Supports natural language tool orchestration, GPIO control, DHT sensors, I2C scanning, and conversation via Telegram or a hosted web relay. Connect to any LLM backend — OpenAI, Anthropic, OpenRouter, or local Ollama.

## Key Features
- 🤖 Conversational AI via Telegram or hosted web relay
- ⏰ Timezone-aware schedules (daily, periodic, one-shot)
- 🔧 Built-in + user-defined tools (GPIO, DHT, I2C, diagnostics)
- 💾 Persistent memory across reboots
- 🔒 Multiple LLM providers: OpenAI / Anthropic / OpenRouter / Ollama
- 🖥️ USB local admin console (no Wi-Fi or LLM required to operate)
- 📦 Firmware size: ≤ 888 KiB total image

## Hardware & Software
- **Hardware components:**
  - Seeed Studio XIAO ESP32-C3 (recommended starter board)
  - Microphone (optional, for voice input)
  - Speaker (optional, for audio output)
  - Display (optional, for visual feedback)
  - DHT11/DHT22 sensor (optional, for temperature/humidity)
  - Dupont wires, prototype board
- **Software / frameworks:**
  - ESP-IDF (build system)
  - FreeRTOS (real-time OS)
  - NimBLE / BLE (Bluetooth)
  - Wi-Fi + TLS/crypto stack
- **Programming language:** C
- **LLM backends:** OpenAI API, Anthropic, OpenRouter, Ollama (local)

## Quick Start

### Software Configuration
  1. Install ESP-IDF following the [official guide](https://docs.espressif.com/projects/esp-idf/)
  2. Clone the repository:
     ```bash
     git clone https://github.com/Seeed-Studio/OSHW-XIAO-Series.git
     cd OSHW-XIAO-Series/projects/community-diy-projects/XIAO_ESP32C3_AI_Assistant
     ```
  3. Run the install script:
     ```bash
     ./install.sh
     ```
  4. Flash the firmware:
     ```bash
     ./scripts/flash.sh
     ```
  5. Provision Wi-Fi and LLM credentials:
     ```bash
     ./scripts/provision.sh
     ```
  6. Reboot the device

### Connecting via Telegram
  After provisioning, send a message to your bot on Telegram. The bot token and chat ID are configured during `provision.sh`.

### Connecting via Web Relay
  Run the hosted web relay for browser-based conversation:
  ```bash
  ./scripts/web-relay.sh
  ```

### Local Admin Console
  Operate the device over USB serial without Wi-Fi or LLM:
  ```bash
  ./scripts/monitor.sh /dev/ttyACM0
  ```
  Available commands: `/wifi status`, `/gpio all`, `/diag`, `/reboot`, `/factory-reset confirm`

## Firmware Size Budget

The 888 KiB budget is all-inclusive:

| Segment | Size |
|---------|------|
| zclaw app logic | ~38 KiB |
| Wi-Fi + networking | ~370 KiB |
| TLS/crypto | ~132 KiB |
| Cert bundle + metadata | ~96 KiB |
| ESP-IDF/runtime/drivers | ~197 KiB |
| **Total** | **~833 KiB** |

## Acknowledgments
- **tnm** ([@tnm](https://github.com/tnm)) — original zclaw firmware and tool architecture
