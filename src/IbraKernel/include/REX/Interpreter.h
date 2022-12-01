#ifndef __INTERPRETER_H
#define __INTERPRETER_H

namespace IbraKernel {
    class REX {
        void Run(char *Program);
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

#endif