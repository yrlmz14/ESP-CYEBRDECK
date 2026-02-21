A 3D Graphics Engine for the ESP32-S3.

Version 2.0 — **ILI9341 LCD Port**

> Forked from [Pescado-Engine-Embedded-ESP32S3](https://github.com/Hykudoru/Pescado-Engine-Embedded-ESP32S3).
> Original project targets the LILYGO T-Display-S3 AMOLED (RM67162, 536×240).
> This version has been adapted for **Waveshare 2.4" ILI9341 LCD (320×240)** on a generic ESP32-S3 board.

## Hardware

| Component | Link / Notes |
|---|---|
| **Board** | Any ESP32-S3 dev board (e.g. ESP32-S3-DevKitC-1) |
| **Display** | Waveshare 2.4" LCD Module (ILI9341, 320×240, SPI) |
| Joysticks (×2) | [SparkFun Qwiic Joystick](https://www.sparkfun.com/products/15168) |
| I²C Mux (×1) | [SparkFun Qwiic Mux – 8 Channel (TCA9548A)](https://www.sparkfun.com/products/16784) |

### Default SPI Wiring (ESP32-S3 → LCD)

| LCD Pin | ESP32-S3 GPIO | Notes |
|---------|--------------|-------|
| VCC     | 3.3 V        |       |
| GND     | GND          |       |
| DIN / MOSI | **GPIO 11** | FSPI data out |
| CLK / SCLK | **GPIO 12** | FSPI clock |
| CS      | **GPIO 10**  | FSPI chip-select |
| DC / RS | **GPIO 13**  | Data / Command |
| RST     | **GPIO 14**  | Hardware reset |
| BL      | **GPIO 21**  | Backlight (active HIGH) |
| MISO    | **GPIO 9**   | Optional read-back |

> **To change pins:** edit `lib/TFT_eSPI-2.5.34/User_Setup.h` (Section 2).

## What Changed from the Original

1. **Display driver** – replaced the RM67162 QSPI/AMOLED driver (`rm67162.cpp`) with a thin wrapper that delegates to TFT_eSPI's ILI9341 support.
2. **Resolution** – framebuffer and projection matrices updated from 536×240 → 320×240.
3. **TFT_eSPI config** – `User_Setup.h` configured for `ILI9341_DRIVER` with ESP32-S3 SPI pins.
4. **PlatformIO** – board changed to `esp32-s3-devkitc-1`; SPI frequency lowered to 40 MHz (safe for ILI9341).
5. **Backlight** – `lcd_init()` now enables the backlight pin.

## .OBJ Format

If using Blender, Export → Wavefront (.obj). Make sure the exported options are:

### Geometry
- Scale: 1.0
- Forward Axis: -Z
- Up Axis: Y
- Colors: True
- Triangulated Mesh: True

### Materials
- Export: True

## Instructions

1. Open the project in VS Code with the PlatformIO extension.
2. Select **Upload Filesystem Image** from PlatformIO to flash the `data/*.obj` files to SPIFFS.
3. Build and upload the firmware to your ESP32-S3.
4. If the screen stays black, try pressing the Reset button or power-cycling the board.

**Upload procedure for ESP32-S3:**
- Step 1. Compile
- Step 2. Plug in USB
- Step 3. (While the old program is running) Hold Boot → Hold Reset → Release Reset → Release Boot
- Step 4. Upload
- Step 5. When uploading finishes, press Reset
