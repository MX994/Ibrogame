#ifndef __RFID_H
#define __RFID_H

#include <vector>
#include <SdFat.h>
#include "Constants.h"
#include <MFRC522.h>

namespace IbraKernel {
    class RFID {
        private:
            MFRC522 *RC522;
        public:
            RFID(uint16_t SS, uint16_t RST);
            bool Init();
            MFRC522 *Get();
    };
};

#endif