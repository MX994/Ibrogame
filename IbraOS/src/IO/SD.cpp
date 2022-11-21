#include <SPI.h>
#include "SdFat.h"
#include <vector>
#include "IO/SD.h"

IbraOS::SD::SD(uint16_t CS) {
    ChipSelect = CS;
    sd = new SdFat;
}

IbraOS::SD::~SD() {
}

bool IbraOS::SD::Init(uint32_t ClockSpeed) {
    return sd->begin(ChipSelect, SD_SCK_MHZ(ClockSpeed));
}

std::vector<uint8_t> IbraOS::SD::ReadFile(std::string Name) {
    std::vector<uint8_t> Data;
    SdFile Current;
    if (Current.open(Name.c_str(), O_RDONLY)) {
        Current.read((uint8_t *)&Data, Current.fileSize());
    }
    Serial.println(Data.size());
    Current.close();
    return Data;
}