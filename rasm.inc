@ Condition enums
.equ LT, 0
.equ GT, 1
.equ LTEQ, 2
.equ GTEQ, 3
.equ EQ, 4
.equ NEQ, 5

@ Opcodes
@ moverr <u8> <u8> 
.macro moverr p0, p1:
.hword 0x1
.byte \p0
.byte \p1
.endm

@ moveri <u8> <u16> 
.macro moveri p0, p1:
.hword 0x2
.byte \p0
.hword \p1
.endm

@ addrr <u8> <u8> 
.macro addrr p0, p1:
.hword 0x3
.byte \p0
.byte \p1
.endm

@ addri <u8> <u16> 
.macro addri p0, p1:
.hword 0x4
.byte \p0
.hword \p1
.endm

@ subrr <u8> <u8> 
.macro subrr p0, p1:
.hword 0x5
.byte \p0
.byte \p1
.endm

@ subri <u8> <u16> 
.macro subri p0, p1:
.hword 0x6
.byte \p0
.hword \p1
.endm

@ ls <u8> <u8> 
.macro ls p0, p1:
.hword 0x7
.byte \p0
.byte \p1
.endm

@ rs <u8> <u8> 
.macro rs p0, p1:
.hword 0x8
.byte \p0
.byte \p1
.endm

@ andrr <u8> <u8> 
.macro andrr p0, p1:
.hword 0x9
.byte \p0
.byte \p1
.endm

@ andri <u8> <u16> 
.macro andri p0, p1:
.hword 0xa
.byte \p0
.hword \p1
.endm

@ orrr <u8> <u8> 
.macro orrr p0, p1:
.hword 0xb
.byte \p0
.byte \p1
.endm

@ orri <u8> <u16> 
.macro orri p0, p1:
.hword 0xc
.byte \p0
.hword \p1
.endm

@ xorrr <u8> <u8> 
.macro xorrr p0, p1:
.hword 0xd
.byte \p0
.byte \p1
.endm

@ xorri <u8> <u16> 
.macro xorri p0, p1:
.hword 0xe
.byte \p0
.hword \p1
.endm

@ cmprr <u8> <u8> <u8> 
.macro cmprr p0, p1, p2:
.hword 0xf
.byte \p0
.byte \p1
.byte \p2
.endm

@ cmpri <u8> <u8> <u16> 
.macro cmpri p0, p1, p2:
.hword 0x10
.byte \p0
.byte \p1
.hword \p2
.endm

@ cjump <u8> <u16> 
.macro cjump p0, p1:
.hword 0x11
.byte \p0
.hword \p1
.endm

@ jump <u16> 
.macro jump p0:
.hword 0x12
.hword \p0
.endm

@ syscall <u16> 
.macro syscall p0:
.hword 0x13
.hword \p0
.endm

@ end 
.macro end 
.hword 0x14
.endm

@ ldrb <u8> <u8> <u16> 
.macro ldrb p0, p1, p2:
.hword 0x15
.byte \p0
.byte \p1
.hword \p2
.endm

@ strbr <u8> <u8> <u16> 
.macro strbr p0, p1, p2:
.hword 0x16
.byte \p0
.byte \p1
.hword \p2
.endm

@ strbi <u8> <u8> <u16> 
.macro strbi p0, p1, p2:
.hword 0x17
.byte \p0
.byte \p1
.hword \p2
.endm

@ ldrh <u8> <u8> <u16> 
.macro ldrh p0, p1, p2:
.hword 0x18
.byte \p0
.byte \p1
.hword \p2
.endm

@ strhr <u8> <u8> <u16> 
.macro strhr p0, p1, p2:
.hword 0x19
.byte \p0
.byte \p1
.hword \p2
.endm

@ strhi <u8> <u16> <u16> 
.macro strhi p0, p1, p2:
.hword 0x1a
.byte \p0
.hword \p1
.hword \p2
.endm

