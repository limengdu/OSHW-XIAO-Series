<div align="center">
<img src="pics/title.png" alt="XIAO_ESP32_NTP_Clock" width="80%">
<br/><br/>

[![PlatformIO](https://img.shields.io/badge/PlatformIO-PlatformIO-red?style=flat&logo=platformio)](https://platformio.org/)
[![ESP32](https://img.shields.io/badge/ESP32-XIAO_ESP32C3-ED7B28?style=flat&logo=seeed)](https://www.seeedstudio.com/xiao-series-page)
[![Arduino](https://img.shields.io/badge/Arduino-C++-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Wi-Fi](https://img.shields.io/badge/Wi--Fi-NTP_Time-4C9EEB?style=flat&logo=wifi)](https://en.wikipedia.org/wiki/Wi-Fi)
</div>

## Creator: [telepath9](https://github.com/telepath9)

We sincerely thank the original author and contributors of [**ESPclock**](https://github.com/telepath9/ESPclock) for their open-source work, which forms the foundation of this project.

## Project Description
A smart NTP network clock powered by Seeed Studio XIAO ESP32 C3. Connects to your home Wi-Fi, fetches time from an NTP server, and displays it on a TM1637 7-segment display. Features a mobile-friendly Web UI for configuring Wi-Fi, NTP server, timezone, brightness, and more — all settings persist across reboots via LittleFS.

## Key Features
- 🌐 NTP network time sync, always accurate
- 📱 Mobile-friendly Web UI for configuration
- 💾 Settings persist across reboots (LittleFS)
- 💡 Auto brightness mode (darker at night, brighter in daylight)
- ⏱️ Toggle colon blink, 12/24-hour format
- 🔧 Built for Seeed Studio XIAO ESP32 C3

## Hardware & Software
- **Hardware components:**
  - Seeed Studio XIAO ESP32 C3
  - TM1637 4-digit 7-segment display module
  - Jumper wires, perfboard (optional 3D-printed case)
- **Software / frameworks:**
  - PlatformIO (build tool)
  - ESPAsyncWebServer (async web server)
  - LittleFS (flash filesystem)
  - ESPmDNS (access via `espclock.local`)
- **Programming language:** C++

## Quick Start

### Hardware Connection
<p align="center">
<img src="pics/xiao_top3_w.jpg" alt="XIAO ESP32 C3 wiring" width="80%">
</p>

<p align="center">

| XIAO ESP32 C3 | TM1637 Display |
|----------------|----------------|
| GPIO 9         | CLK            |
| GPIO 10        | DIO            |
| 3V3            | VCC            |
| GND            | GND            |

</p>

### Software Configuration
  1. Install [VSCode](https://code.visualstudio.com/) or [VSCodium](https://vscodium.com/)
  2. Install **PlatformIO IDE** extension
  3. Clone or download the project, open `esp32/` directory

  <p align="center">
  <img src="pics/pic1.jpg" alt="ESPclock hardware" width="80%">
  </p>

  4. Build and flash:
     - `Platform → Build filesystem image` (upload web UI to flash)
     - `Platform → Upload` (flash firmware)
  5. Connect to ESP's AP (SSID: `ESPclock32`, password: `waltwhite64`)
  6. Open `http://192.168.4.1/` or `http://espclock.local/` in your browser

  <p align="center">
  <img src="pics/v2.2.jpg" alt="Web UI" width="40%">
  </p>

  7. Configure your home Wi-Fi, NTP server, and timezone via the Web UI

  8. Once everything is working, assemble the hardware and enclose it in the case

  <p align="center">
  <img src="pics/howtoassemble.webp" alt="How to assemble" width="80%">
  </p>
