#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "IO/Display.h"

IbraKernel::Display::Display(uint16_t TFTChipSelect, uint16_t TFTDC, uint16_t TS_XMin, uint16_t TS_XMax, uint16_t TS_YMin, uint16_t TS_YMax) {
    TFT = new Adafruit_HX8357(TFTChipSelect, TFTDC, -1);
}

bool IbraKernel::Display::Init() {
    TFT->begin();
    return true;
}

Adafruit_HX8357 *IbraKernel::Display::GetTFT() {
    return TFT;
}

