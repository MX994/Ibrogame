#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "IO/Touchscreen.h"

IbraKernel::Display::Display(uint16_t TFTChipSelect, uint16_t TFTDC) {
    TFT = new Adafruit_HX8357(TFTChipSelect, TFTDC, -1);
}

Adafruit_HX8357 *IbraKernel::Display::GetTFT() {
    return TFT;
}

