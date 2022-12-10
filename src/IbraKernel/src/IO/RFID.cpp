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

bool IbraKernel::RFID::Read(uint8_t Blk, uint8_t *Buffer, uint16_t *Size) {
  return PollAndWork(false, Blk, Buffer, Size);
}

bool IbraKernel::RFID::Write(uint8_t Blk, uint8_t *Buffer, uint16_t *Size) {
  return PollAndWork(true, Blk, Buffer, Size);
}

bool IbraKernel::RFID::PollAndWork(bool Write, uint8_t BlkNum, uint8_t *Buffer, uint16_t *Size) {
  while (!RC522->PICC_IsNewCardPresent() || !RC522->PICC_ReadCardSerial());

  if (RC522->PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, AUTH_BLK, &Key, &RC522->uid)) {
    RC522->PICC_HaltA();
    RC522->PCD_StopCrypto1();
    return false;
  }

  if ((Write ? RC522->MIFARE_Write(BlkNum, Buffer, *Size) : RC522->MIFARE_Read(BlkNum, Buffer, (uint8_t *)Size))) {
    RC522->PICC_HaltA();
    RC522->PCD_StopCrypto1();
    return false;
  }

  return true;
}

