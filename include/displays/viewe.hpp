
#pragma once
#include <Arduino.h>

#include "Arduino_GFX_Library.h"
#include "TouchDrvCSTXXX.hpp"

#include "pins.h"

#define TFT_BLACK 0x00000

#define CO5300_MX 0x40
#define CO5300_MY 0x80

#define FLIP_NONE 0
#define FLIP_X 1
#define FLIP_Y 2
#define FLIP_XY 3

class DisplayWrapper
{
public:
    Arduino_DataBus *bus;
    Arduino_GFX *gfx;
    TouchDrvCSTXXX touch;

    DisplayWrapper()
    {

        bus = new Arduino_ESP32QSPI(
            LCD_CS /* CS */, LCD_SCK /* SCK */, LCD_SD0 /* SDIO0 */, LCD_SD1 /* SDIO1 */,
            LCD_SD2 /* SDIO2 */, LCD_SD3 /* SDIO3 */);

        gfx = new Arduino_CO5300(
            bus,
            LCD_RST /* RST */,
            0 /* rotation */,
            false /* IPS */,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            6 /* col_offset1 */,
            0 /* row_offset1 */,
            0 /* col_offset2 */,
            0 /* row_offset2 */
        );
    }

    bool init(void)
    {
#ifdef LCD_EN
        pinMode(LCD_EN, OUTPUT);
        digitalWrite(LCD_EN, HIGH);
#endif
        bool state = gfx->begin();
        touch.setPins(TOUCH_RST, TOUCH_IRQ);
        touch.begin(Wire, 0x15, TOUCH_SDA, TOUCH_SCL);
        return state;
    }

    void initDMA(void) {}

    void fillScreen(uint16_t color)
    {
        gfx->fillScreen(color);
    }

    void setRotation(uint8_t rotation)
    {
        // gfx->setRotation(rotation); // Not supported in CO5300
    }

    void setFlipMode(uint8_t mode)
    {
        uint8_t cmd = 0;
        switch (mode)
        {
        case FLIP_NONE:
            flip_x = false;
            flip_y = false;
            break;
        case FLIP_X:
            flip_x = true;
            flip_y = false;
            cmd |= CO5300_MX;
            break;
        case FLIP_Y:
            flip_x = false;
            flip_y = true;
            cmd |= CO5300_MY;
            break;
        case FLIP_XY:
            flip_x = true;
            flip_y = true;
            cmd |= CO5300_MX | CO5300_MY;
            break;
        default:
            break;
        }
        bus->beginWrite();
        bus->writeC8D8(CO5300_W_MADCTL, cmd);
        bus->endWrite();
    }

    void pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data)
    {
        gfx->draw16bitBeRGBBitmap(x, y, data, w, h);
    }

    void pushImageDMA(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data)
    {
        gfx->draw16bitBeRGBBitmap(x, y, data, w, h);
    }

    void startWrite(void) {}

    uint32_t getStartCount(void)
    {
        return 0;
    }

    void endWrite(void) {}

    void setBrightness(uint8_t brightness)
    {
        ((Arduino_CO5300 *)gfx)->setBrightness(brightness);
    }

    void writePixel(int32_t x, int32_t y, const uint16_t color)
    {
        gfx->writePixel(x, y, color);
    }

    bool getTouch(uint16_t *x, uint16_t *y)
    {
        int16_t x_arr[5], y_arr[5];
        uint8_t touched = touch.getPoint(x_arr, y_arr, touch.getSupportTouchPoint());

        if (flip_x)
        {
            // adjust for HUD mode (mirrored)
            for (uint8_t i = 0; i < touched; i++)
            {
                x_arr[i] = SCREEN_WIDTH - x_arr[i];
            }
        }
        if (flip_y)
        {
            // adjust for HUD mode (mirrored)
            for (uint8_t i = 0; i < touched; i++)
            {
                y_arr[i] = SCREEN_HEIGHT - y_arr[i];
            }
        }
        *x = x_arr[0];
        *y = y_arr[0];
        return touched;
    }

private:
    bool flip_x = false;
    bool flip_y = false;
};

DisplayWrapper tft;