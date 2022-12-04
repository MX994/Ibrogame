#ifndef __MJOLNIR_H
#define __MJOLNIR_H

#include <map>

namespace IbraKernel {
    class Mjolnir {
        public:
            void Call(uint8_t Syscall, uint32_t *Registers);
    };
};

#endif