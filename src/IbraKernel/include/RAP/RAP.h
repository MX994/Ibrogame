#ifndef __RAP_H
#define __RAP_H

#include <Arduino.h>
#include <vector>

namespace IbraKernel {
    class RAP {
        public:
            RAP();
            std::vector<uint8_t> GetIcon(std::vector<uint8_t> Buf);
            std::vector<uint8_t> GetREX(std::vector<uint8_t> Buf);
    };
};

#endif