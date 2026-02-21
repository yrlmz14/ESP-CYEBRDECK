#pragma once

// ---------------------------------------------------------------------------
// ILI9341 LCD display driver — drop-in replacement for the RM67162 AMOLED
// driver.  All heavy lifting is done by TFT_eSPI; these functions just keep
// the same call-sites compiling so the rest of the engine is unchanged.
// ---------------------------------------------------------------------------

#include "stdint.h"

void lcd_init(void);
void lcd_setRotation(uint8_t r);
void lcd_PushColors(uint16_t x, uint16_t y, uint16_t width, uint16_t high, uint16_t *data);
void lcd_PushColors(uint16_t *data, uint32_t len);
void lcd_fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color);
void lcd_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
void lcd_address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void lcd_sleep();
void lcd_brightness(uint8_t bright);
void lcd_display_off();
void lcd_display_on();

// Kept for backward compatibility — maps to lcd_init()
inline void rm67162_init(void) { lcd_init(); }
