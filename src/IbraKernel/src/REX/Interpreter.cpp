#include "REX/Interpreter.h"

void IbraKernel::REX::Run(char *Program) {
    uint32_t Registers[0x10];
    uint8_t RAM[0x400];
    while (true) {
        uint16_t Operation = *(uint16_t *)(Program + Registers[PC]);
        Registers[PC] += sizeof(uint16_t);
        switch (Operation) {
            case moverr: {
                // moverr <dest> <src>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Src = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Src);

                Registers[Dest] = Registers[Src];
                break;
            }
            case moveri: {
                // moveri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(uint16_t *)(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] = Val;
                break;
            }
            case addrr: {
                // addrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] += Registers[AmtReg];
                break;
            }
            case addri: {
                // addri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *((uint16_t *) (Program + Registers[PC]));
                Registers[PC] += sizeof(Val);

                Registers[Dest] += Val;
                break;
            }
            case subrr: {
                // subrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] -= Registers[AmtReg];
                break;
            }
            case subri: {
                // subri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *((uint16_t *) (Program + Registers[PC]));
                Registers[PC] += sizeof(Val);

                Registers[Dest] -= Val;
                break;
            }
            case ls: {
                // ls <dest> <amt>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Amt = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Amt);

                Registers[Dest] <<= Amt;
                break;
            }
            case rs: {
                // rs <dest> <amt>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t Amt = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Amt);

                Registers[Dest] >>= Amt; 
                break; 
            }
            case andrr: {
                // andrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] &= Registers[AmtReg];
                break;
            }
            case andri: {
                // andri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] &= Val; 
                break;
            }
            case orrr: {
                // orrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] |= Registers[AmtReg];
                break;
            }
            case orri: {
                // orri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] |= Val; 
                break;
            }
            case xorrr: {
                // xorrr <dest> <amt_reg>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint8_t AmtReg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(AmtReg);

                Registers[Dest] ^= Registers[AmtReg];
                break;
            }
            case xorri: {
                // xorri <dest> <imm>
                uint8_t Dest = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Dest);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                Registers[Dest] ^= Val; 
                break;
            }
            case cmprr: {
                // cmprr <op1> <cmp_instr> <op2>
                uint8_t Op1Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op1Reg);

                uint8_t CompInst = *(Program + Registers[PC]);
                Registers[PC] += sizeof(CompInst);

                uint8_t Op2Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op2Reg);

                CompareSetCondReg(Op1Reg, CompInst, Op2Reg, &Registers[CND]);
                break;
            }
            case cmpri: {
                // cmpri <op1> <cmp_instr> <imm>
                uint8_t Op1Reg = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Op1Reg);

                uint8_t CompInst = *(Program + Registers[PC]);
                Registers[PC] += sizeof(CompInst);

                uint16_t Val = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Val);

                CompareSetCondReg(Op1Reg, CompInst, Val, &Registers[CND]);
                break;
            }
            case cjump: {
                // cjump
                uint8_t Expected = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Expected);

                int16_t RelJumpOffset = *(Program + Registers[PC]);
                Registers[PC] += sizeof(RelJumpOffset);

                if (Registers[CND] == Expected) {
                    Registers[PC] = (uint32_t)(Registers[PC] + RelJumpOffset);
                }
                break;
            }
            case jump: {
                //jump
                int16_t JumpOffset = *(Program + Registers[PC]);
                Registers[PC] += sizeof(JumpOffset);

                Registers[PC] = (uint32_t)(Registers[PC] + JumpOffset);
                break;
            }
            case syscall: {
                // syscall
                uint16_t SyscallNum = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SyscallNum);
                break;
            }
            case ret: {
                // ret
                return;
            }
            case ldrb: {
                // ldrb <dest> <src> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint8_t SrcRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SrcRegister);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                Registers[DestRegister] = *((uint8_t *)Registers[SrcRegister] + Shift);
                break;
            }
            case strbr: {
                // strbr <dest> <src> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint8_t SrcRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SrcRegister);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                *((uint8_t *)Registers[DestRegister] + Shift) = Registers[SrcRegister];
                break;
            }
            case strbi: {
                // strbi <dest> <imm> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint8_t Immediate = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Immediate);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                *((uint8_t *)Registers[DestRegister] + Shift) = Immediate;
                break;
            }      
            case ldrh: {
                // ldrh <dest> <src> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint8_t SrcRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SrcRegister);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                Registers[DestRegister] = *((uint16_t *)((uint8_t *)Registers[SrcRegister] + Shift));
                break;
            }
            case strhr: {
                // strhr <dest> <src> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint8_t SrcRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(SrcRegister);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                *((uint16_t *)((uint8_t *)Registers[DestRegister] + Shift)) = Registers[SrcRegister];
                break;
            }
            case strhi: {
                // strhi <dest> <imm> <shift>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);

                uint16_t Immediate = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Immediate);

                uint16_t Shift = *(Program + Registers[PC]);
                Registers[PC] += sizeof(Shift);

                *((uint16_t *)((uint8_t *)Registers[DestRegister] + Shift)) = Immediate;
                break;   
            }       
            case ldstring: {
                // ldstring <dest> <string>
                uint8_t DestRegister = *(Program + Registers[PC]);
                Registers[PC] += sizeof(DestRegister);
                size_t StringLength = strlen(Program + Registers[PC]) + 1;
                Registers[DestRegister] = (uint32_t)malloc(StringLength);
                memcpy((uint8_t *)Registers[DestRegister], Program + Registers[PC], StringLength);
            }
            default: {
                Serial.print("Unrecognized opcode. Opcode was ");
                Serial.println(Operation);
                Serial.println("Exiting VM...");
                return;
            }
        }
    }
}

void IbraKernel::REX::CompareSetCondReg(uint16_t LHS, uint16_t RHS, uint8_t Compare, uint32_t *Condition) {
    switch (Compare) {
        case LT:
            *Condition = LHS < RHS; 
            break;
        case GT:
            *Condition = LHS > RHS;
            break;
        case LTEQ:
            *Condition = LHS <= RHS;
            break;
        case GTEQ:
            *Condition = LHS >= RHS;
            break;
        case EQ:
            *Condition = LHS == RHS;
            break;
        case NEQ:
            *Condition = LHS != RHS;
            break;
    }
}

