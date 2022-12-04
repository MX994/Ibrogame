#include "IO/IO.h"

bool IbraKernel::IO::Init() {
    EEPROM = new IbraKernel::SD(SD_CS);
    Display = new IbraKernel::Display(TFT_CS, TFT_DC, -1, -1, -1, -1);
    RFID = new IbraKernel::RFID(RFID_SS, RFID_RST);

    if (!Display->Init()) {
        Serial.println("Failed to initialize display. Boot halted!");
        return false;
    }

    Display->GetTFT()->setRotation(0);
    Display->GetTFT()->setTextColor(HX8357_BLACK);
    Display->GetTFT()->fillScreen(HX8357_BLACK);

    if (!EEPROM->Init(50)) {
        Serial.println("Failed to initialize SD card; check if it is properly inserted. Boot halted!");
        return false;
    }
    
    return true;
}