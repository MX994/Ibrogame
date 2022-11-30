#include <SPI.h>
#include <Adafruit_GFX.h>
#include "Adafruit_HX8357.h"
#include "IO/Display.h"

IbraKernel::Display::Display(uint16_t TFTChipSelect, uint16_t TFTDC) {
    TFT = new Adafruit_HX8357(TFTChipSelect, TFTDC, -1);
}
void IbraKernel::Display::Init() {
    TFT->begin();
}
void IbraKernel::Display::WriteText(std::string Text) {
    TFT->println(Text.c_str());
}
void IbraKernel::Display::DrawBitmap(int x, int y, int w, int h, int Color, uint8_t *Bitmap) {
    TFT->drawBitmap(x, y, Bitmap, w, h, Color);
}
void IbraKernel::Display::Clear(bool Black) {
    TFT->fillScreen(Black ? HX8357_BLACK : HX8357_WHITE);
}