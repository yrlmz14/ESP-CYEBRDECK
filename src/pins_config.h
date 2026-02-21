#pragma once

/***********************config*************************/
// ILI9341 uses standard SPI, not QSPI
#define LCD_USB_QSPI_DREVER   0

#define SPI_FREQUENCY         40000000
#define TFT_SPI_MODE          SPI_MODE0
#define TFT_SPI_HOST          SPI2_HOST

#define EXAMPLE_LCD_H_RES     320
#define EXAMPLE_LCD_V_RES     240
#define LVGL_LCD_BUF_SIZE     (EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES)

#define WIFI_CONNECT_WAIT_MAX (30 * 1000)

#define NTP_SERVER1           "pool.ntp.org"
#define NTP_SERVER2           "time.nist.gov"
#define GMT_OFFSET_SEC        0
#define DAY_LIGHT_OFFSET_SEC  0

#define GET_TIMEZONE_API      "https://ipapi.co/timezone/"

/***********************config*************************/

#define LCD_WIDTH             320
#define LCD_HEIGHT            240
#define SEND_BUF_SIZE         (0x4000)

// ILI9341 SPI pin definitions (active when NOT using TFT_eSPI)
// These mirror the TFT_eSPI User_Setup.h defaults; change both if re-wiring.
#define PIN_LCD_DC            13
#define PIN_LCD_RES           14
#define PIN_LCD_CS            10
#define PIN_LCD_MOSI          11
#define PIN_LCD_SCK           12
#define PIN_LCD_BL            21

#define PIN_LED               38
#define PIN_BAT_VOLT          4

#define PIN_BUTTON_1          0
#define PIN_BUTTON_2          21
