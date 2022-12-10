#include "System/Mjolnir.h"
#include "IO/IO.h"

void IbraKernel::Mjolnir::Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM) {
    switch (Syscall) {
        case 0: {
            IbraKernel::IO::Display->GetTFT()->println((char *)&WKRAM[Registers[0]]);
            break;
        }
        case 1: {
            // drawPixel
            IbraKernel::IO::Display->GetTFT()->drawPixel(Registers[0], Registers[1], Registers[2]);
            break;
        }
        case 2: {
            // fillRect
            IbraKernel::IO::Display->GetTFT()->fillRect(Registers[0], Registers[1], Registers[2], Registers[3], Registers[4]);
            break;
        }
        case 3: {
            // left joystick get x
            Registers[0] = IbraKernel::IO::LeftJoystick->GetX();
            break;
        }
        case 4: {
            // left joystick get y
            Registers[0] = IbraKernel::IO::LeftJoystick->GetY();
            break;
        }

        case 5: {
            // left joystick get switch input
            Registers[0] = IbraKernel::IO::LeftJoystick->GetSWPressed();
            break;
        }
        case 6: {
            // left joystick get x
            Registers[0] = IbraKernel::IO::RightJoystick->GetX();
            break;
        }
        case 7: {
            // left joystick get y
            Registers[0] = IbraKernel::IO::RightJoystick->GetY();
            break;
        }
        case 8: {
            // left joystick get switch input
            Registers[0] = IbraKernel::IO::RightJoystick->GetSWPressed();
            break;
        }
        case 9: {
            // RFID read
            Registers[0] = IbraKernel::IO::RFID->Read(Registers[0], &WKRAM[Registers[1]], &Registers[2]);
            break;
        }
        case 10: {
            // RFID write
            Registers[0] = IbraKernel::IO::RFID->Write(Registers[0], &WKRAM[Registers[1]], &Registers[2]);
            break;
        }
        
        // // Bluetooth Init
        // case 11: {
        //     IbraKernel::IO::Bluetooth->Init();
        //     break;
        // }

        // // Bluetooth Connect
        // case 12: {
        //     IbraKernel::IO::Bluetooth->Connect(WKRAM[Registers[0]]);
        //     break;
        // }

        // // Bluetooth Send
        // case 13: {
        //     IbraKernel::IO::Bluetooth->Send(WKRAM[Registers[0]]);
        //     break;
        // }

        // // Bluetooth receive
        // case 14: {
        //     IbraKernel::IO::Bluetooth->Recv(WKRAM[Registers[0]]);
        //     break;
        // }

        // // Bluetooth disconnect
        // case 15: {
        //     IbraKernel::IO::Bluetooth->Disconnect();
        //     break;
        // }

        // // Bluetooth stop
        // case 16: {
        //     IbraKernel::IO::Bluetooth->Stop();
        //     break;
        // }

        default:
            break;
    }
}