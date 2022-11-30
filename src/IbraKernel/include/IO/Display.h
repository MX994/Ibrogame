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
            Display(uint16_t TFTChipSelect, uint16_t TFTDC);
            void Init();
            void DrawBitmap(int x, int y, int w, int h, int Color, uint8_t *Bitmap);
            void WriteText(std::string Text);
            void Clear(bool Black);
    };
};

#endif 