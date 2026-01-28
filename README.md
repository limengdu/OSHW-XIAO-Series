# [Seeed Studio XIAO Series](https://www.seeedstudio.com/xiao-series-page?utm_source=github&utm_medium=seeed&utm_campaign=xiaoseries)

## Product Family Overview
<p align="center" width="100%"><a href="https://github.com/Seeed-Studio/OSHW-XIAO-Series/blob/main/document/Seeed_Studio_XIAO_Slides.pdf">
<img src="/image/slides.png" alt="alt text" width="1000">
</a>
</p>


The Seeed Studio XIAO Series is a collection of thumb-sized, powerful microcontroller units (MCUs) tailor-made for space-conscious projects requiring high performance and wireless connectivity. Embodying the essence of popular hardware platforms such as ESP32, RP2040, nRF52840, and SAMD21, the Arduino-compatible XIAO series is the perfect toolset for you to embrace tiny machine learning (TinyML) on the Edge.The whole XIAO Series features compact design with all SMD components placed on the same side of the board, so designers can easily integrate XIAO into their boards for rapid mass production.

This repository is the official GitHub Project Hub for the XIAO Series, serving as a aggregated entry point for product overview, selection guidance, specifications, documentation, internal reference projects, and community-driven DIY works.

**Contents**

[Product Lineup and Selection Guide](#product-lineup-and-selection-guide)

[Wiki and Learning](#wiki-and-learning)

[Reference Projects](#reference-projects)

[DIY Community Projects](#diy-community-projects)

[How to Contribute](#how-to-contribute)

[Roadmap](#roadmap)

[Support](#support)

---


## Product Lineup and Selection Guide

### XIAO Dev Boards

<table align="center">
<font size={"2"}>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/57e09470-7f82-4b29-9f0b-ee24c20f881f" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO ESP32-S3 (Sense)</strong><br>High-performance dev board with Wi-Fi and BLE, with Microphone, Mini camera and onboard SD Card Slot on the Sense version</td>
        <td align="center" width= "200"><a href="https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/d4ae565b-52cf-4b33-9a1b-2d7c73cdd4b5" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO ESP32-C3</strong><br>Cost effective with Wi-Fi and BLE on board</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/cba9e163-a265-4be3-9ec3-a4be86620aa3" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO ESP32-C6</strong><br>2.4GHz Wi-Fi 6, BLE 5.0, Zigbee, and Thread for Matter</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C6-p-5884.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/b46cf0d4-034f-4011-b687-38f60edc4084" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO ESP32-C5</strong><br>2.4 & 5 GHz Wi-Fi 6, BLE 5.0, Zigbee, and Thread for Matter</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C5-p-6609.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/xiao_esp32c5_getting_started/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/cd97c5da-6dfa-4940-ad58-cc6d1e44c679" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO nRF52840 (Sense)</strong><br>Ultra-low power consumption, perfect for BLE applications, with microphone and 6-axis IMU on the Sense version</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-XIAO-BLE-Sense-nRF52840-p-5253.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/XIAO_BLE/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/2006c0de-fe68-4f96-b3b2-2cd402b5f0c7" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO nRF54L15 (Sense)</strong><br>Ultra low power consumption with multiple connectivity, with microphone and 6-axis IMU on the Sense version</td>
        <td align="center"><a href="https://www.seeedstudio.com/XIAO-nRF54L15-Sense-p-6494.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/xiao_nrf54l15_sense_getting_started/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/2364e006-5bfc-4519-898c-95812d0a66ea" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO RP2040</strong><br>Raspberry Pi Ecosystem with great MicroPython support</td>
        <td align="center"><a href="https://www.seeedstudio.com/XIAO-RP2040-v1-0-p-5026.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/XIAO-RP2040/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/55895340-c212-471f-9d3b-7005894e3fee" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO RP2350</strong><br>MicroPython-ready based on Raspberry Pi RP2350</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-XIAO-RP2350-p-5944.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/getting-started-xiao-rp2350/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/2ac6fbf3-bf96-4040-ad21-05320b775672" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO SAMD21</strong><br>Classic for Arduino beginners, with courses</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/Seeeduino-XIAO/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/b4e07414-23ed-43f5-9fe2-cee58670066a" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO RA4M1</strong><br>Renesas 32-bit ARM Cortex-M4 MCU, Arduino IDE-ready</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-XIAO-RA4M1-p-5943.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/getting_started_xiao_ra4m1/" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
	<tr>
	    <td align="center"><img src="https://github.com/user-attachments/assets/b5ed4e13-85f5-4bdd-bd6e-fafa8e187001" alt="alt text" height="200" width= auto></td>
		<td><strong>XIAO MG24 (Snese)</strong><br>Super-low power for battery-powered Matter projects, with microphone and 6-axis IMU on the Sense version</td>
        <td align="center"><a href="https://www.seeedstudio.com/Seeed-XIAO-MG24-Sense-p-6248.html" target="_blank"><b><strong>🖱️ Buy Now</strong></b></a><br>
		<a href="https://wiki.seeedstudio.com/xiao_mg24_getting_started" target="_blank"><b><strong>📚 Getting Started</strong></b></a></td>
	</tr>
</font>
</table>

---
## Wiki and Learning



---

## Reference Projects

---

## DIY Community Projects

---

## How to Contribute

---

## Roadmap

---

## Support

---
