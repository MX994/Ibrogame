#ifndef __SD_H
#define __SD_H

#include <vector>
#include <SdFat.h>

namespace IbraKernel {
    class SD {
        private:
            SdFat *sd;
            uint16_t ChipSelect;
        public:
            SD(uint16_t CS = 2);
            ~SD();
            bool Init(uint32_t ClockSpeed);
            std::vector<uint8_t> ReadFile(std::string Name);
    };
};

typedef struct {
    SdFile* Curr;
} SDWork;

#endif