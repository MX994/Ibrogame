#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "TouchScreen.h"

#define TS_MINX 110
#define TS_MINY 80
#define TS_MAXX 900
#define TS_MAXY 940

namespace IbraKernel {
    class Display {
        private:
            Adafruit_HX8357 *TFT;
            TouchScreen *TS;
        public:
            Display(uint16_t TFTChipSelect, uint16_t TFTDC, uint16_t TS_XMin, uint16_t TS_XMax, uint16_t TS_YMin, uint16_t TS_YMax);
            bool Init();
            int GetTouchX();
            int GetTouchY();
            int GetTouchZ();
            Adafruit_HX8357 *GetTFT();
    };
};

#endif 