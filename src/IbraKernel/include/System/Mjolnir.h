#ifndef __MJOLNIR_H
#define __MJOLNIR_H

#include <map>
#include <vector>

namespace IbraKernel {
    class Mjolnir {
        public:
            static void Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM, std::map<int, int> &WKRAM_Map, std::vector<std::vector<uint8_t>> &Applets);
    };
};

#endif