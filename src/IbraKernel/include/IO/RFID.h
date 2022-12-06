#ifndef __RFID_H
#define __RFID_H

#include <vector>
#include <SdFat.h>
#include <MFRC522.h>

#define AUTH_BLK 0x3

namespace IbraKernel {
    class RFID {
        private:
            MFRC522 *RC522;
        public:
            RFID(uint16_t SS, uint16_t RST);
            bool Init();
            bool Read();
            bool Write();
            bool PollAndDoWork();
    };
};

#endif