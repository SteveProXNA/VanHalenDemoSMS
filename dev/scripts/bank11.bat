@echo off
REM albums

cd ..
cd banks
cd bank11


:: Tiles
bmp2tile.exe "raw\VanHalen1988.bmp" -savetiles "VanHalen1988 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1988 (tilemap).stmcompr" -savepalette "VanHalen1988 (palette).bin" -fullpalette -exit


cd ..
folder2c bank11 bank11 11

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK11 bank11.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts