#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"

namespace IbraKernel {
    class Display {
        private:
            Adafruit_HX8357 *TFT;
        public:
            Display(uint16_t TFTChipSelect, uint16_t TFTDC, uint16_t TS_XMin, uint16_t TS_XMax, uint16_t TS_YMin, uint16_t TS_YMax);
            bool Init();
            Adafruit_HX8357 *GetTFT();
    };
};

#endif 