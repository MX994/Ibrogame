#include "System/Mjolnir.h"
#include "IO/IO.h"

void IbraKernel::Mjolnir::Call(uint8_t Syscall, uint32_t *Registers) {
    switch (Syscall) {
        case 0: {
            IbraKernel::IO::Display->GetTFT()->println((char *)Registers[0]);
            break;
        }
        default:
            break;
    }
}