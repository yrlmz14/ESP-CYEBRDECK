// ---------------------------------------------------------------------------
// ILI9341 LCD display driver — drop-in replacement for the RM67162 AMOLED
// driver.  Delegates to TFT_eSPI which already knows how to talk ILI9341.
// ---------------------------------------------------------------------------

#include "rm67162.h"
#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void lcd_init(void)
{
    tft.init();
    tft.fillScreen(TFT_BLACK);

#ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
#endif
}

void lcd_setRotation(uint8_t r)
{
    tft.setRotation(r);
}

void lcd_address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    tft.setAddrWindow(x1, y1, x2 - x1 + 1, y2 - y1 + 1);
}

void lcd_fill(uint16_t xsta, uint16_t ysta,
              uint16_t xend, uint16_t yend,
              uint16_t color)
{
    tft.fillRect(xsta, ysta, xend - xsta, yend - ysta, color);
}

void lcd_DrawPoint(uint16_t x, uint16_t y, uint16_t color)
{
    tft.drawPixel(x, y, color);
}

void lcd_PushColors(uint16_t x, uint16_t y,
                    uint16_t width, uint16_t high,
                    uint16_t *data)
{
    tft.pushImage(x, y, width, high, data);
}

void lcd_PushColors(uint16_t *data, uint32_t len)
{
    tft.pushPixels(data, len);
}

void lcd_sleep()
{
    tft.writecommand(0x10);
}

void lcd_brightness(uint8_t bright)
{
#ifdef TFT_BL
    analogWrite(TFT_BL, bright);
#endif
}

void lcd_display_off()
{
    tft.writecommand(0x28);
}

void lcd_display_on()
{
    tft.writecommand(0x29);
}
