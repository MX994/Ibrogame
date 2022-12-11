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
        Current.close();
    }
    return Data;
}

std::vector<std::string> IbraKernel::SD::ListFiles(std::string Directory) {
    std::vector<std::string> Files;
    SdFile Dir, Current;
    if (Dir.open(Directory.c_str())) {
        while (Current.openNext(&Dir, O_RDONLY)) {
            if (Current.isFile()) {
                char NameBuffer[0x20];
                Current.getName(NameBuffer, 0x20);
                Files.push_back(NameBuffer);
            }
            Current.close();
        }
    }
    Serial.println(Files.size());
    return Files;
}

SdFile *IbraKernel::SD::GetFileStream(std::string Path) {
    if (OFT.count(Path)) {
        return OFT[Path];
    }
    return NULL;
}