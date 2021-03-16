@echo off
REM albums

cd ..
cd banks
cd bank8


:: Tiles
bmp2tile.exe "raw\VanHalen1982.bmp" -savetiles "VanHalen1982 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1982 (tilemap).stmcompr" -savepalette "VanHalen1982 (palette).bin" -fullpalette -exit


cd ..
folder2c bank8 bank8 8

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK8 bank8.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts