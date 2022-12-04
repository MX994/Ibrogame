#include "System/Mjolnir.h"
#include "IO/IO.h"

void IbraKernel::Mjolnir::Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM) {
    switch (Syscall) {
        case 0: {
            Serial.println(Registers[0]);
            Serial.println((char *)&WKRAM[Registers[0]]);
            IbraKernel::IO::Display->GetTFT()->println((char *)&WKRAM[Registers[0]]);
            break;
        }
        default:
            break;
    }
}