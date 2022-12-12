#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "IO/Display.h"

IbraKernel::Display::Display(uint16_t TFTChipSelect, uint16_t TFTDC, uint16_t TS_XMin, uint16_t TS_XMax, uint16_t TS_YMin, uint16_t TS_YMax) {
    TFT = new Adafruit_HX8357(TFTChipSelect, TFTDC, -1);
    this->TS_XMin = TS_XMin;
    this->TS_XMax = TS_XMax;
    this->TS_YMin = TS_YMin;
    this->TS_YMax = TS_YMax;
}

bool IbraKernel::Display::Init() {
    TFT->begin();
    return true;
}

Adafruit_HX8357 *IbraKernel::Display::GetTFT() {
    return TFT;
}

int IbraKernel::Display::GetTouchX() {
    // Adafruit's version didn't work. This is functionally equivalent.
    pinMode(TS_YMax, INPUT);
    pinMode(TS_YMin, INPUT);
    digitalWrite(TS_YMax, LOW);
    digitalWrite(TS_YMin, LOW);

    pinMode(TS_XMax, OUTPUT);
    digitalWrite(TS_XMax, HIGH);
    pinMode(TS_XMin, OUTPUT);
    digitalWrite(TS_XMin, LOW);
    return map(1023 - analogRead(TS_YMax), TS_MINX, TS_MAXX, 0, TFT->width());
}

int IbraKernel::Display::GetTouchY() {
    pinMode(TS_XMax, INPUT);
    pinMode(TS_XMin, INPUT);
    digitalWrite(TS_XMax, LOW);
    digitalWrite(TS_XMin, LOW);

    pinMode(TS_YMax, OUTPUT);
    digitalWrite(TS_YMax, HIGH);
    pinMode(TS_YMin, OUTPUT);
    digitalWrite(TS_YMin, LOW);
    return map(1023 - analogRead(TS_XMin), TS_MINY, TS_MAXY, 0, TFT->height());
}

int IbraKernel::Display::GetTouchZ() {
    return TS->getPoint().z;
}