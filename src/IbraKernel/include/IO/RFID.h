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
            bool PollAndWork(bool Write, uint8_t BlkNum, uint8_t *Buffer, uint16_t *Size);
            MFRC522::MIFARE_Key Key;
        public:
            RFID(uint16_t SS, uint16_t RST);
            bool Init();
            bool Read(uint8_t Blk, uint8_t *Buffer, uint16_t *Size);
            bool Write(uint8_t Blk, uint8_t *Buffer, uint16_t *Size);
    };
};

#endif