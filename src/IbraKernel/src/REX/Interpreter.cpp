#include "REX/Interpreter.h"

void IbraKernel::REX::Run(char *Program) {
    uint32_t Registers[0x10];
    uint8_t RAM[0x400];
    while (true) {
        uint16_t Operation = *(uint16_t *)(Program + Registers[PC]);
        Registers[PC] += sizeof(uint16_t);
        switch (Operation) {
            case moverr:
                // moverr <dest> <src>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Src = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Src);

                Registers[Dest] = Registers[Src];
                break;
            case moveri:
                // moveri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(uint16_t *)(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] = Val;
                break;
            case addrr:
                // addrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] += Registers[AmtReg];
                break;
            case addri:
                // addri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *((uint16_t) (Program + Registers[PC]));
                Registers[PC] += sizeof(Val);

                Registers[Dest] += Val;
                break;
            case subrr:
                // subrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] -= Registers[AmtReg];
                break;
            case subri:
                // subri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *((uint16_t) (Program + Registers[PC]));
                Registers[PC] += sizeof(Val);

                Registers[Dest] -= Val;
                break;
            case ls:
                // ls <dest> <amt>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Amt = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Amt);

                Registers[Dest] <<= Amt;
                break;
            case rs:
                // rs <dest> <amt>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Amt = *(Program + Registers[PC]);
                Registers[PC] += sizeof[Amt]

                Registers[Dest] >>= Amt; 
                break;
            case andrr:
                // andrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] &= Registers[AmtReg];
                break;
            case andri:
                // andri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] &= Val; 
                break;
            case orrr:
                // orrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] |= Registers[AmtReg];
                break;
            case orri:
                // orri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] |= Val; 
                break;
            case xorrr:
                // xorrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] ^= Registers[AmtReg];
                break;
            case xorri:
                // xorri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] ^= Val; 
                break;
            case cmprr:
                // cmprr <op1> <cmp_instr> <op2>
                uint8_t Op1Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op1Reg);

                uint8_t CompInst = *(Program + Registers[PC]);
                Registers[PC] += sizeof(CompInst);

                unit8_t Op2Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op2Reg);

                CompareSetCondReg(Op1Reg, CompInst, Op2Reg, &Registers[CND]);
                break;
            case cmpri:
                // cmpri <op1> <cmp_instr> <imm>
                uint8_t Op1Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op1Reg);

                uint8_t CompInst = *(Program + Registers[PC]);
                Registers[PC] += sizeof(CompInst);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                CompareSetCondReg(Op1Reg, CompInst, Op2Reg, &Registers[CND]);
                break;
            case cjump:
                // cjump
                uint8_t Expected = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Expected);

                int16_t RelJumpOffset = *(Program + Registers[PC]);
                Registers[PC] += sizeof(RelJumpOffset);

                if (Registers[CND] == Expected) {
                    Registers[PC] = (uint32_t)(Registers[PC] + RelJumpOffset);
                }
                break;
            case jump:
                //jump
                int16_t JumpOffset = *(Program + Registers[PC]);
                Registers[PC] += sizeof(JumpOffset);

                Registers[PC] = (uint32_t)(Registers[PC] + RelJumpOffset);
                break;
            case syscall:
                // syscall
                uint16_t SyscallNum = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SyscallNum);
                break;
            case end:
            default:
                return;
        }
    }
}

void IbraKernel::REX::CompareSetCondReg(uint16_t LHS, uint16_t RHS, uint8_t Compare, uint32_t *Condition) {
    // TODO: Set Condition to boolean result of each compare statement.
    switch (Compare) {
        case 0x0:
            break;
        case 0x1:
            break;
        case 0x2:
            break;
        case 0x3:
            break;
        case 0x4:
            break;
        case 0x5:
            break;
        case 0x6:
            break;
        case 0x7:
            break;
    }
}

