#include "RAP/RAP.h"

IbraKernel::RAP::RAP() {

}

std::vector<uint8_t> IbraKernel::RAP::GetIcon(std::vector<uint8_t> Buf) {

}

std::vector<uint8_t> IbraKernel::RAP::GetREX(std::vector<uint8_t> Buf) {
    std::vector<uint8_t> Ret;
    uint16_t Addr = Buf[0x18] | (Buf[0x19] << 0x8), Size = Buf[0x1A] | (Buf[0x1B] << 0x8);
    for (int i = Addr; i < Addr + Size; ++i) {
        Ret.push_back(Buf[i]);
    }
    return Ret;
}