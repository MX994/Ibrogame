#include "IbraKernel.h"

#include <SPI.h>
#include <Arduino.h>
#include <vector>
#include "Adafruit_GFX.h"

IbraKernel::SD EEPROM(SD_CS);
IbraKernel::Display Display(TFT_CS, TFT_DC, -1, -1, -1, -1);
IbraKernel::RFID RFID(RFID_SS, RFID_RST);

void KernelBootAnimation(void);

void setup(void) {
  Serial.begin(9600);
  SPI.begin();
  Display.Init();
  Display.GetTFT()->setTextColor(HX8357_BLACK);
  if (!EEPROM.Init(50)) {
    Display.GetTFT()->print("Failed to initialize SD card. Boot halted!");
    return;
  }
  KernelBootAnimation();
}

void KernelBootAnimation() {
  Display.GetTFT()->fillScreen(HX8357_WHITE);
  Display.GetTFT()->setTextSize(5);
  Display.GetTFT()->setCursor(68, 240);

  // Draw IbraOS logo.
  Display.GetTFT()->setTextColor(HX8357_BLACK);
  Display.GetTFT()->println("IbraOS");

  // Draw subtext.
  Display.GetTFT()->setTextSize(2);
  Display.GetTFT()->setCursor(105, 300);
  Display.GetTFT()->println("Prerelease");
}

void loop() {
  // RC522 test code. Should be put in its own library.
  if (RFID.Get()->PICC_IsNewCardPresent() && RFID.Get()->PICC_ReadCardSerial()) {
    for (byte i = 0; i < RFID.Get()->uid.size; ++i)  {
      Display.GetTFT()->print(RFID.Get()->uid.uidByte[i]);
    }
  }
}