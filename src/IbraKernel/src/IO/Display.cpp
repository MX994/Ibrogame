#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "IO/Display.h"
#include "TouchScreen.h"

IbraKernel::Display::Display(uint16_t TFTChipSelect, uint16_t TFTDC, uint16_t TS_XMin, uint16_t TS_XMax, uint16_t TS_YMin, uint16_t TS_YMax) {
    TFT = new Adafruit_HX8357(TFTChipSelect, TFTDC, -1);
    TS = new TouchScreen(TS_XMax, TS_YMax, TS_XMin, TS_YMin, 300);
}

bool IbraKernel::Display::Init() {
    TFT->begin();
    return true;
}

Adafruit_HX8357 *IbraKernel::Display::GetTFT() {
    return TFT;
}

int IbraKernel::Display::GetTouchX() {
    return map(TS->getPoint().x, TS_MINX, TS_MAXX, 0, TFT->width());
}

int IbraKernel::Display::GetTouchY() {
    return map(TS->getPoint().y, TS_MINX, TS_MAXX, 0, TFT->height());;
}

int IbraKernel::Display::GetTouchZ() {
    return TS->getPoint().z;
}