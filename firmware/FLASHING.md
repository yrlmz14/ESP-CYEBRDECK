# Flashing Pre-built Firmware

Pre-built binaries for the **ESP32-S3-N16R8** with **Waveshare 2.4" ILI9341 LCD**.

## Files

| File | Description | Flash Address |
|------|-------------|--------------|
| `bootloader.bin` | ESP32-S3 bootloader | `0x0` |
| `partitions.bin` | Partition table (default_16MB) | `0x8000` |
| `boot_app0.bin` | OTA boot selector | `0xe000` |
| `firmware.bin` | Application firmware | `0x10000` |
| `spiffs.bin` | SPIFFS filesystem (3D models) | `0xc90000` |

## Option 1: Flash with esptool (recommended)

### Install esptool

```
pip install esptool
```

### Put ESP32-S3 into download mode

1. Hold the **BOOT** button
2. Press and release the **RESET** button
3. Release the **BOOT** button

The board should now appear as a USB serial device.

### Flash everything at once

Open a terminal / command prompt, `cd` into the `firmware/` folder, then run the command for your OS.

Find your serial port first:
- **Windows:** Open Device Manager → Ports (COM & LPT) → look for `COM3`, `COM4`, etc.
- **Linux:** typically `/dev/ttyACM0` or `/dev/ttyUSB0`
- **macOS:** typically `/dev/cu.usbmodem*`

#### Windows (Command Prompt)

Replace `COM3` with your actual COM port:

```
esptool --chip esp32s3 --port COM3 --baud 921600 --before default_reset --after hard_reset write_flash --flash_mode qio --flash_size 16MB 0x0 bootloader.bin 0x8000 partitions.bin 0xe000 boot_app0.bin 0x10000 firmware.bin 0xc90000 spiffs.bin
```

#### Windows (PowerShell)

```powershell
esptool --chip esp32s3 --port COM3 --baud 921600 `
  --before default_reset --after hard_reset `
  write_flash --flash_mode qio --flash_size 16MB `
  0x0 bootloader.bin `
  0x8000 partitions.bin `
  0xe000 boot_app0.bin `
  0x10000 firmware.bin `
  0xc90000 spiffs.bin
```

#### Linux / macOS

```bash
esptool.py --chip esp32s3 --port /dev/ttyACM0 --baud 921600 \
  --before default_reset --after hard_reset \
  write_flash --flash_mode qio --flash_size 16MB \
  0x0      bootloader.bin \
  0x8000   partitions.bin \
  0xe000   boot_app0.bin \
  0x10000  firmware.bin \
  0xc90000 spiffs.bin
```

### Flash only the firmware (if SPIFFS is already flashed)

**Windows:**
```
esptool --chip esp32s3 --port COM3 --baud 921600 write_flash --flash_mode qio --flash_size 16MB 0x10000 firmware.bin
```

**Linux / macOS:**
```bash
esptool.py --chip esp32s3 --port /dev/ttyACM0 --baud 921600 \
  write_flash --flash_mode qio --flash_size 16MB \
  0x10000 firmware.bin
```

### Flash only the 3D models (SPIFFS)

**Windows:**
```
esptool --chip esp32s3 --port COM3 --baud 921600 write_flash --flash_mode qio --flash_size 16MB 0xc90000 spiffs.bin
```

**Linux / macOS:**
```bash
esptool.py --chip esp32s3 --port /dev/ttyACM0 --baud 921600 \
  write_flash --flash_mode qio --flash_size 16MB \
  0xc90000 spiffs.bin
```

## Option 2: Flash with the Espressif Web Flasher (no install needed)

1. Go to https://espressif.github.io/esptool-js/
2. Connect your ESP32-S3 via USB (put it in download mode first)
3. Click **Connect** and select the serial port
4. Add each file with its address:
   - `0x0` → `bootloader.bin`
   - `0x8000` → `partitions.bin`
   - `0xe000` → `boot_app0.bin`
   - `0x10000` → `firmware.bin`
   - `0xc90000` → `spiffs.bin`
5. Click **Program**

## Option 3: Flash with PlatformIO (if you have the project)

```
pio run -e esp32s3-ili9341 -t upload
pio run -e esp32s3-ili9341 -t uploadfs
```

## After Flashing

Press the **RESET** button. The 3D engine should start rendering on your ILI9341 LCD.

If you see a black screen, check:
- Wiring matches the pin table in the main README
- Backlight pin (BL) is connected to GPIO 21
- The LCD is powered at 3.3V
