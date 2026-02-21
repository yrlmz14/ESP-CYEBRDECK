//                            USER DEFINED SETTINGS
//   Set driver type, fonts to be loaded, pins used and SPI control method etc.
//
//   Configured for: Waveshare 2.4" ILI9341 LCD on ESP32-S3
//
//   If you need different GPIO pins, edit Section 2 below.

#define USER_SETUP_INFO "Waveshare_2.4_ILI9341_ESP32S3"

// ##################################################################################
//
// Section 1. Call up the right driver file and any options for it
//
// ##################################################################################

#define ILI9341_DRIVER

// ##################################################################################
//
// Section 2. Define the pins that are used to interface with the display here
//
// ##################################################################################

// ---------- ESP32-S3 SPI pin mapping for Waveshare 2.4" ILI9341 LCD ----------
// Adjust these pins to match YOUR wiring. The defaults below use the ESP32-S3
// FSPI-capable GPIOs which give the best SPI performance.
//
//  LCD Pin  ->  ESP32-S3 GPIO
//  -------      -------------
//  VCC      ->  3.3V
//  GND      ->  GND
//  DIN/MOSI ->  GPIO 11
//  CLK/SCLK ->  GPIO 12
//  CS       ->  GPIO 10
//  DC/RS    ->  GPIO 13
//  RST      ->  GPIO 14
//  BL       ->  GPIO 21  (active HIGH)
//  MISO     ->  GPIO 9   (optional, for read-back)

#define TFT_MISO  9
#define TFT_MOSI  11
#define TFT_SCLK  12
#define TFT_CS    10
#define TFT_DC    13
#define TFT_RST   14

#define TFT_BL    21
#define TFT_BACKLIGHT_ON HIGH

// ##################################################################################
//
// Section 3. Define the fonts that are to be used here
//
// ##################################################################################

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

// ##################################################################################
//
// Section 4. Other options
//
// ##################################################################################

// 40 MHz is reliable for ILI9341; some displays handle 80 MHz
#define SPI_FREQUENCY       40000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000
