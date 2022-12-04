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
  Display.Init();
  Display.GetTFT()->setRotation(0);
  Display.GetTFT()->setTextColor(HX8357_BLACK);
  if (!EEPROM.Init(50)) {
    Display.GetTFT()->print("Failed to initialize SD card. Boot halted!");
    Serial.println("Bruh");
    return;
  }
  KernelBootAnimation();
}

void KernelBootAnimation() {
  Display.GetTFT()->setRotation(1);
  Display.GetTFT()->fillScreen(HX8357_WHITE);

  // Draw IbraOS logo.
  Display.GetTFT()->setCursor(150, 150);
  Display.GetTFT()->setTextColor(HX8357_BLACK);
  Display.GetTFT()->setTextSize(5);
  Display.GetTFT()->println("IbraOS");

  // Draw subtext.
  // Display.GetTFT()->setTextSize(2);
  // Display.GetTFT()->setCursor((480 >> 2) - strlen("Prerelease"), 170);
  // Display.GetTFT()->println("Prerelease");
}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
  // Serial.println(analogRead(A1));
  // Serial.println(analogRead(A2));
  // Serial.println(analogRead(A3));
}