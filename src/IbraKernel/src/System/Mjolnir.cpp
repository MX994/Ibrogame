#include "System/Mjolnir.h"
#include "IO/IO.h"

void IbraKernel::Mjolnir::Call(uint8_t Syscall, uint16_t *Registers, uint8_t *WKRAM, std::map<int, int> &WKRAM_Map) {
    switch (Syscall) {
        case 0: {
            // Switch on Register 1 so we don't have to redefine lmao
            if (!Registers[1]) {
                IbraKernel::IO::Display->GetTFT()->print((char *)&WKRAM[Registers[0]]);
            } else {                    
                IbraKernel::IO::Display->GetTFT()->println((char *)&WKRAM[Registers[0]]);
            }
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
            Serial.println(Registers[0]);
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
        case 11: {
            // List Files.
            std::vector<std::string> Files = IbraKernel::IO::EEPROM->ListFiles((char *)&WKRAM[Registers[0]]);
            uint16_t Skip = 0;
            for (int Elem = 0; Elem < Files.size(); ++Elem) {
                sprintf((char *)&WKRAM[Registers[1] + Skip], Files[Elem].c_str());
                Skip += Files[Elem].size() + 1;
            }
            Registers[0] = Files.size();
            break;
        }
        case 12: {
            // strlen
            Registers[0] = strlen((char *)&WKRAM[Registers[0]]);
            break;
        }
        case 13: {
            // memalloc
            Serial.print("Alloc of size:");
            Serial.println(Registers[0]);
            uint16_t WKRAMPtr = 0;
            while (WKRAM_Map.count(WKRAMPtr)) {
                if (WKRAMPtr > 8192) {
                    // Cannot allocate any WKRAM; return.
                    return;
                }
                WKRAMPtr += WKRAM_Map[WKRAMPtr];
            }
            // Found WKRAM; add to the entry.
            WKRAM_Map.insert({WKRAMPtr, Registers[0]});

            for (int i = WKRAMPtr; i < WKRAMPtr + Registers[0]; ++i) {
                // Init with all 0.
                WKRAM[i] = 0;
            }
            Registers[0] = WKRAMPtr;
            Serial.println(Registers[0]);
            break;
        }
        case 14: {
            // memfree
            break;
        }
        case 15: {
            // setFontSize
            IbraKernel::IO::Display->GetTFT()->setTextSize(Registers[0]);
            break;
        }
        case 16: {
            IbraKernel::IO::Display->GetTFT()->setTextColor(Registers[0]);
            break;
        }
        case 17: {
            Registers[0] = IbraKernel::IO::Display->GetTouchX();
            break;
        }
        case 18: {
            Registers[0] = IbraKernel::IO::Display->GetTouchY();
            break;
        }
        case 19: {
            Registers[0] = IbraKernel::IO::Display->GetTouchZ();
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