#include <SPI.h>
#include <map>
#include "IO/SD.h"

IbraKernel::SD::SD(uint16_t CS) {
    ChipSelect = CS;
    sd = new SdFat;
}

bool IbraKernel::SD::Init(uint32_t ClockSpeed) {
    return sd->begin(ChipSelect, SD_SCK_MHZ(ClockSpeed));
}

std::vector<uint8_t> IbraKernel::SD::ReadFile(std::string Name) {
    std::vector<uint8_t> Data;
    SdFile Current;
    if (Current.open(Name.c_str(), O_RDONLY)) {
        while (Current.curPosition() < Current.fileSize()) {
            Data.push_back(Current.read());
        }
        for (int i = 0; i < Data.size(); ++i) {
            Serial.println(Data[i], HEX);
        }
        Current.close();
    }
    return Data;
}

SdFile *IbraKernel::SD::GetFileStream(std::string Path) {
    if (OFT.count(Path)) {
        return OFT[Path];
    }
    return NULL;
}