from argparse import ArgumentParser
from pathlib import Path
from subprocess import check_output, CalledProcessError
from sys import stderr, exit

AS = 'arm-none-eabi-as.exe'
OBJCOPY = 'arm-none-eabi-objcopy.exe'

def Subproc(cmd):
	try:
		check_output(cmd)
	except CalledProcessError as e:
		print(e.output.decode(), file = stderr)
		exit(1)

def MakeREX(RASM : Path, REX : Path):
	Subproc([AS, '-c', RASM.as_posix(), '-o', f'{RASM.stem}.o'])
	print(REX.as_posix())
	Subproc([OBJCOPY, '-O', 'binary', f'{RASM.stem}.o', REX.as_posix()])
	Path(f'{RASM.stem}.o').unlink()


if __name__ == "__main__":
	Parser = ArgumentParser(prog = 'rexgen', description = 'Assembles a .rasm file into the .rex format.')
	Parser.add_argument('rasm')
	Parser.add_argument('rex')
	Arguments = Parser.parse_args()
	Src, Target = Path(Arguments.rasm), Path(Arguments.rex)
	MakeREX(Src, Target)