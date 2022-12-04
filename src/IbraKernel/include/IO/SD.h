#ifndef __SD_H
#define __SD_H

#include <vector>
#include <map>
#include <SdFat.h>

namespace IbraKernel {
    class SD {
        private:
            std::map<std::string, SdFile*> OFT;
            SdFat *sd;
            uint16_t ChipSelect;
        public:
            SD(uint16_t CS);
            bool Init(uint32_t ClockSpeed);
            std::vector<uint8_t> ReadFile(std::string Name);
            SdFile *GetFileStream(std::string Path);
    };
};

#endif