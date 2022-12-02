#include <SPI.h>
#include "IO/RFID.h"

IbraKernel::RFID::RFID(uint16_t SS, uint16_t RST) {
    RC522 = new MFRC522(SS, RST);
}

bool IbraKernel::RFID::Init() {
  SPI.begin();
  RC522->PCD_Init();
  return true;
}

MFRC522 *IbraKernel::RFID::Get() {
    return RC522;
}

