#include <Arduino.h>
#include <vector>
#include "IbraOS.h"

#define TFT_DC 9
#define TFT_CS 10

#define SD_CS 2

IbraOS::SD EEPROM(SD_CS);
IbraOS::Display Disp(TFT_CS, TFT_DC);

void setup(void) {
  Serial.begin(9600);
  Disp.Init();
  Disp.Clear(true);
  if (!EEPROM.Init(50)) {
    Disp.WriteText("Failed to initialize SD card. Boot halted!");
    return;
  }
  Serial.println("Printing data...");
  uint8_t *BootLogo = &EEPROM.ReadFile("/boot/splash.bmp")[0];
  Serial.println((uint32_t)BootLogo);
  Disp.DrawBitmap(0, 0, 320, 480, 0xFFFFFF, BootLogo);
  Serial.println("It worked!");
}


void loop() {
}