@echo off
REM albums

cd ..
cd banks
cd bank7


:: Tiles
bmp2tile.exe "raw\VanHalen1981.bmp" -savetiles "VanHalen1981 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1981 (tilemap).stmcompr" -savepalette "VanHalen1981 (palette).bin" -fullpalette -exit


cd ..
folder2c bank7 bank7 7

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 bank7.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts