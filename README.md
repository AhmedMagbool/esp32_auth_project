# ESP32 Login System with ILI9341 + Tuwaiq Logo

**Author:** Ahmed  
**Year:** 2025  
**Platform:** ESP32  
**Display:** ILI9341 (Resistive Touch, SPI Interface)  
**Project Language:** C++ (Arduino Framework)

---

## 📋 Description

This project simulates a simple **account creation and login system** using the ESP32 and an **ILI9341 TFT screen**. The user interacts via the **Serial Monitor**, and the interface visually responds with updates and messages on the screen.

It also displays the **Tuwaiq Academy logo** in 64x64 resolution at the top right corner with the label "Tuwaiq Academy" under it.

---

## 🎯 Features

- Serial-based UI for:
  - Creating a new username/password
  - Logging in with stored credentials
- Error handling for invalid inputs
- Clean, responsive UI drawn to the ILI9341 TFT screen
- Tuwaiq Academy logo rendered from a 0/1 bitmap
- Lightweight and suitable for demos or education

---

## 🖥️ Screenshot

![image](https://github.com/user-attachments/assets/8a1eff4d-bc0a-4b1a-83e8-e22dee3f2b22)



---

## 🖼️ Tuwaiq Logo

The logo is stored as a 64×64 bitmap (0/1) and drawn pixel by pixel on the screen.

File: `tuwaiq_logo_64x64_clean.h`

---

## 🔌 Pinout Table (ESP32 ↔ ILI9341)

| TFT Function | ESP32 Pin | Description                |
|--------------|-----------|----------------------------|
| `TFT_CS`     | GPIO 15   | Chip Select                |
| `TFT_DC`     | GPIO 2    | Data/Command               |
| `TFT_RST`    | GPIO 4    | Reset                      |
| `TFT_SCLK`   | GPIO 18   | SPI Clock (Hardware SPI)   |
| `TFT_MOSI`   | GPIO 23   | SPI Data (MOSI)            |
| `TFT_MISO`   | GPIO 19   | Not used in this project   |
| `GND`        | GND       | Ground                     |
| `VCC`        | 3.3V      | Power Supply for Display   |

> ⚠️ Make sure `TFT_CS`, `TFT_DC`, `TFT_RST` are correctly assigned in code.  
> We use hardware SPI pins by default (`SCLK = 18`, `MOSI = 23`).

---

## 🚀 How to Use

1. Flash the code to your ESP32 using Arduino IDE or PlatformIO.
2. Open **Serial Monitor** at 115200 baud.
3. Type `create` to register a new user, or `login` to authenticate.
4. Follow on-screen prompts.

---

## 🧠 Future Ideas

- Add touch support to select between buttons (if resistive touch input is connected).
- Store credentials in EEPROM or SPIFFS.
- Extend to support multiple users.

---

## 📁 Files in this repo

- `sketch.ino` – Main logic and UI system
- `tuwaiq_logo_64x64_clean.h` – Logo bitmap
- `diagram.json` – Optional Wokwi circuit diagram
- `preview.png` – Optional screenshot

---

## 📷 Credit

Logo: [Tuwaiq Academy](https://tuwaiq.edu.sa/)  
Built on [Wokwi Simulator](https://wokwi.com/)

---

**Made with ❤️ by Ahmed – Tuwaiq 2025**
