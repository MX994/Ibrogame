#include "IO/Joystick.h"

IbraKernel::Joystick::Joystick(uint16_t XPin, uint16_t YPin, uint16_t SWPin) {
    this->XPin = XPin;
    this->YPin = YPin;
    this->SWPin = SWPin;
}

uint16_t IbraKernel::Joystick::GetX() {
    return analogRead(XPin);
}

uint16_t IbraKernel::Joystick::GetY() {
    return analogRead(YPin);
}

bool IbraKernel::Joystick::GetSWPressed() {
    return digitalRead(SWPin);
}