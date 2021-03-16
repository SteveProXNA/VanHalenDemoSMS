@echo off
REM albums

cd ..
cd banks
cd bank5


:: Tiles
bmp2tile.exe "raw\VanHalen1979.bmp" -savetiles "VanHalen1979 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1979 (tilemap).stmcompr" -savepalette "VanHalen1979 (palette).bin" -fullpalette -exit


cd ..
folder2c bank5 bank5 5

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK5 bank5.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts