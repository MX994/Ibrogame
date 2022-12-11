#ifndef __MJOLNIR_H
#define __MJOLNIR_H

#include <map>

namespace IbraKernel {
    class Mjolnir {
        public:
            static void Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM, std::map<int, int> WKRAM_Map);
    };
};

#endif