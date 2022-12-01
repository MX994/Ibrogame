#ifndef __INTERPRETER_H
#define __INTERPRETER_H

namespace IbraKernel {
    class REX {
        void Run(char *Program);
        void CompareSetCondReg(uint16_t LHS, uint16_t RHS, uint8_t Compare, uint32_t *Condition);
    };
};

// Registers 
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define CND 12
#define SP 13
#define LR 14
#define PC 15

// Operation codes.
#define moverr 1
#define moveri 2
#define addrr 3
#define addri 4
#define subrr 5
#define subri 6
#define ls 7
#define rs 8
#define andrr 9
#define andri 10
#define orrr 11
#define orri 12
#define xorr 13
#define xori 14
#define cmprr 15
#define cmpri 16
#define cjump 17
#define jump 18
#define syscall 19
#define end 20
#define ldrb 21
#define strbr 22
#define strbi 23
#define ldrh 24
#define strhr 25
#define strhi 26

// Comparisons
// 'LT', 'GT', 'LTEQ', 'GTEQ', 'EQ', 'NEQ'
#define LT 0
#define GT 1
#define LTEQ 2
#define GTEQ 3
#define EQ 4
#define NEQ 5

#endif