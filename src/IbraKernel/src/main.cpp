#include "IbraKernel.h"

#include <SPI.h>
#include <Arduino.h>
#include <vector>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include <MFRC522.h>

IbraKernel::SD EEPROM(SD_CS);
Adafruit_HX8357 Display(TFT_CS, TFT_DC, -1);
MFRC522 RC522(RFID_SS, RFID_RST);

void KernelBootAnimation(void);

void setup(void) {
  Serial.begin(9600);
  Display.begin();
  if (!EEPROM.Init(50)) {
    Display.println("Failed to initialize SD card. Boot halted!");
    return;
  }
  SPI.begin();
  RC522.PCD_Init();
  KernelBootAnimation();
}

void KernelBootAnimation() {
  Display.fillScreen(HX8357_WHITE);
  Display.setTextSize(5);
  Display.setCursor(68, 240);

  // Draw IbraOS logo.
  Display.setTextColor(HX8357_BLACK);
  Display.println("IbraOS");

  // Draw subtext.
  Display.setTextSize(2);
  Display.setCursor(105, 300);
  Display.println("Prerelease");
}

void loop() {
  // RC522 test code. Should be put in its own library.
  if (RC522.PICC_IsNewCardPresent() && RC522.PICC_ReadCardSerial()) {
    for (byte i = 0; i < RC522.uid.size; ++i)  {
      Display.print(RC522.uid.uidByte[i]);
    }
  }
}