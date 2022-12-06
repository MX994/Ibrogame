#include <Arduino.h>

namespace IbraKernel {
    class Joystick {
        public:
            Joystick(uint16_t XPin, uint16_t YPin, uint16_t SW);
            bool Init();
            uint16_t GetX();
            uint16_t GetY();
            bool GetSWPressed();
    };
};