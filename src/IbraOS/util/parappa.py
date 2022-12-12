from argparse import ArgumentParser
from pathlib import Path
from subprocess import check_output, CalledProcessError
from sys import stderr, exit
from yaml import load, Loader
from rexgen import MakeREX
import os
from PIL import Image
from struct import pack
import shutil

Parser = ArgumentParser(prog = 'Parappa', description = 'Creates a .rap (Ronan Application Package)')
Parser.add_argument('config')
Arguments = Parser.parse_args()

IMAGE_MAX_WIDTH = 32
IMAGE_MAX_HEIGHT = 32

ConfigurationPath = Arguments.config

if not os.path.exists('build'):
    os.mkdir('build')
if not os.path.exists(os.path.join('build', 'apps')):
    os.mkdir(os.path.join('build', 'apps'))

with open(Arguments.config, 'r') as YAML:
    Dumped = load(YAML, Loader=Loader)
    for k, v in Dumped.items():
        print(f'[+] Compiling \"{k}\"...')

        # Regardless of if this is an app, make the .rex first.
        SrcPath = Path(os.path.realpath(os.path.dirname(__file__)), '../apps', v['Source'])
        MakeREX(SrcPath, SrcPath.parent / f'{v["OutputName"]}.rex')

        # If this is an app, pack it in a structure.
        if 'IsApp' in v.keys():
            Title = k[:0x10]
            IconSize = (IMAGE_MAX_WIDTH * IMAGE_MAX_HEIGHT) << 1
            REXBuf = open(SrcPath.parent / f'{v["OutputName"]}.rex', 'rb').read()

            # Make header
            Buffer = b'RAPP'
            Buffer += Title.encode() + b'\0' * (0x10 - len(Title))
            Buffer += pack('<H', 28) # Icon start address; right after header
            Buffer += pack('<H', IconSize) # Icon size
            Buffer += pack('<H', IconSize + 28) # REX start address, right after icon
            Buffer += pack('<H', len(REXBuf)) # sizeof(REX)

            ImagePath = SrcPath.parent.parent / f'{v["AppImage"]}'
            Icon = Image.open(ImagePath).convert('RGB')
            if Icon.width > IMAGE_MAX_WIDTH or Icon.height > IMAGE_MAX_HEIGHT:
                print(f'[-] Error making "{k}": Image width and height must satisfy w : [0, {IMAGE_MAX_WIDTH}], h : [0, {IMAGE_MAX_HEIGHT}]')
                continue

            # Convert image to RGB 565 colors.
            # Each image is 64x64, will take 2 bytes = 8192 bytes.
            # Note to self: write image, then clear.
            for y in range(Icon.height):
                for x in range(Icon.width):
                    Pixel = Icon.getpixel((x, y))
                    Red, Green, Blue = (Pixel[0] >> 3) & 0x1F, (Pixel[1] >> 2) & 0x3F, (Pixel[2] >> 3) & 0x1F
                    Buffer += pack('<H', Red << 0xB | Green << 0x5 | Blue)

            # Store programs
            Buffer += REXBuf 

            with open(SrcPath.parent / f'{v["OutputName"]}.rap', 'wb') as RAP:
                RAP.write(Buffer)
                RAP.close()
                
            shutil.copyfile(SrcPath.parent / f'{v["OutputName"]}.rap', os.path.join('build', 'apps', f'{v["OutputName"]}.rap'))            
        else:
            shutil.copyfile(SrcPath.parent / f'{v["OutputName"]}.rex', os.path.join('build', f'{v["OutputName"]}.rex'))
    YAML.close()
