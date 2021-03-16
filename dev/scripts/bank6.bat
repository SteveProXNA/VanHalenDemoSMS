@echo off
REM albums

cd ..
cd banks
cd bank6


:: Tiles
bmp2tile.exe "raw\VanHalen1980.bmp" -savetiles "VanHalen1980 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1980 (tilemap).stmcompr" -savepalette "VanHalen1980 (palette).bin" -fullpalette -exit


cd ..
folder2c bank6 bank6 6

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK6 bank6.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts