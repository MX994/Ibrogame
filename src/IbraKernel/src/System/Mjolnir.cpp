#include "System/Mjolnir.h"
#include "IO/IO.h"

void IbraKernel::Mjolnir::Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM) {
    switch (Syscall) {
        // text print
        case 0: {
            IbraKernel::IO::Display->GetTFT()->println((char *)&WKRAM[Registers[0]]);
            break;
        }

        // drawPixel
        case 1: {
            IbraKernel::IO::Display->GetTFT()->drawPixel(WKRAM[Registers[0]],
                                                        WKRAM[Registers[1]],
                                                        WKRAM[Registers[2]]);
            break;
        }

        // fill screen
        case 2: {
            IbraKernel::IO::Display->GetTFT()->writeFillRect(WKRAM[Registers[0]],
                                                            WKRAM[Registers[1]],
                                                            WKRAM[Registers[2]],
                                                            WKRAM[Registers[3]],
                                                            WKRAM[Registers[4]]);
            break;
        }

        // left joystick get x
        case 3: {
            WKRAM[Registers[0]] = IbraKernel::IO::LeftJoystick->GetX();
            break;
        }

        // left joystick get y
        case 4: {
            WKRAM[Registers[0]] = IbraKernel::IO::LeftJoystick->GetY();
            break;
        }

        // left joystick get switch input
        case 5: {
            WKRAM[Registers[0]] = IbraKernel::IO::LeftJoystick->GetSWPressed();
            break;
        }

        // right joystick get x
        case 6: {
            WKRAM[Registers[0]] = IbraKernel::IO::RightJoystick->GetX();
            break;
        }

        // right joystick get y
        case 7: {
            WKRAM[Registers[0]] = IbraKernel::IO::RightJoystick->GetY();
            break;
        }

        // right joystick get switch input
        case 8: {
            WKRAM[Registers[0]] = IbraKernel::IO::RightJoystick->GetSWPressed();
            break;
        }

        // RFID read
        case 9: {
            WKRAM[Registers[0]] = IbraKernel::IO::RFID->Read();
            break;
        }

        // RFID write
        case 10: {
            IbraKernel::IO::RFID->Write() = WKRAM[Registers[0]];
            break;
        }
        
        // Bluetooth Init
        case 11: {
            IbraKernel::IO::Bluetooth->Init();
            break;
        }

        // Bluetooth Connect
        case 12: {
            IbraKernel::IO::Bluetooth->Connect(WKRAM[Registers[0]]);
            break;
        }

        // Bluetooth Send
        case 13: {
            IbraKernel::IO::Bluetooth->Send(WKRAM[Registers[0]]);
            break;
        }

        // Bluetooth receive
        case 14: {
            IbraKernel::IO::Bluetooth->Recv(WKRAM[Registers[0]]);
            break;
        }

        // Bluetooth disconnect
        case 15: {
            IbraKernel::IO::Bluetooth->Disconnect();
            break;
        }

        // Bluetooth stop
        case 16: {
            IbraKernel::IO::Bluetooth->Stop();
            break;
        }

        default:
            break;
    }
}