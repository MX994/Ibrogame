#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

#include <Arduino.h>
#include <ArduinoBLE.h>

namespace IbraKernel {
    class Bluetooth {
        public:
            bool Init();
            void Connect();
            void Advertise();
            bool IsConnected();
            bool Read(uint8_t *Buffer, uint16_t Size);
            bool Write(uint8_t *Buffer, uint16_t Size);
            void Disconnect();
    };
};

#endif