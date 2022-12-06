#ifndef __IO_H
#define __IO_H

#include "HardwareMap.h"

#include "IO/Bluetooth.h"
#include "IO/Display.h"
#include "IO/Joystick.h"
#include "IO/RFID.h"
#include "IO/SD.h"

namespace IbraKernel {
    class IO {
        private:
            uint16_t XPin, YPin, SWPin;
        public:
            Joystick(uint16_t XPin, uint16_t YPin, uint16_t SWPin);
            inline static IbraKernel::Bluetooth* Bluetooth;
            inline static IbraKernel::SD* EEPROM;
            inline static IbraKernel::Display* Display;
            inline static IbraKernel::Joystick *LeftJoystick, *RightJoystick; 
            inline static IbraKernel::RFID* RFID;
    };
}; 

#endif