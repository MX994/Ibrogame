Operations = {
    # Arithmetic
    'moverr' : ['u8', 'u8'],
    'moveri' : ['u8', 'u16'],

    'addrr' : ['u8', 'u8'],
    'addri' : ['u8', 'u16'],

    'subrr' : ['u8', 'u8'],
    'subri' : ['u8', 'u16'],

    'ls' : ['u8', 'u8'],
    'rs' : ['u8', 'u8'],

    'andrr' : ['u8', 'u8'],
    'andri' : ['u8', 'u16'],

    'orrr' : ['u8', 'u8'],
    'orri' : ['u8', 'u16'],

    'xorrr' : ['u8', 'u8'],
    'xorri' : ['u8', 'u16'],

    'cmprr' : ['u8', 'u8' ,'u8'],
    'cmpri' : ['u8', 'u8', 'u16'],

    # Control
    'cjump' : ['u8', 'u16'],
    'jump' : ['u16'],
    'syscall' : ['u16'],
    'end' : [],
}

Conditions = ['LT', 'GT', 'LTEQ', 'GTEQ', 'EQ', 'NEQ']

with open('rasm.inc', 'w') as Macros:
    # Write conditions.
    Macros.write('@ Condition enums\n')
    for Condition in Conditions:
        Macros.write(f'.equ {Condition}, {Conditions.index(Condition)}\n')
    Macros.write('\n')

    # Write opcodes.
    OpcodeNum = 1
    Macros.write('@ Opcodes\n')
    for Operation, Parameters in Operations.items():
        Macros.write(f'@ {Operation} ')
        for x in Parameters:
            Macros.write(f'<{x}> ')
        Macros.write('\n')
        Macros.write(f'.macro {Operation} ')
        for x in range(len(Parameters)):
            Macros.write(f'p{x}{":" if x == len(Parameters) - 1 else ", "}')
        Macros.write('\n')
        Macros.write(f'.hword {hex(OpcodeNum)}\n')
        for x in range(len(Parameters)):
            Macros.write(f'{".hword" if Parameters[x] == "u16" else ".byte"} \p{x}')
            Macros.write('\n')
        Macros.write('.endm\n\n')
        OpcodeNum += 1
    Macros.close()



