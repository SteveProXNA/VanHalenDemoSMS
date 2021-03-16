@echo off
REM albums

cd ..
cd banks
cd bank13


:: Tiles
bmp2tile.exe "raw\VanHalen1995.bmp" -savetiles "VanHalen1995 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1995 (tilemap).stmcompr" -savepalette "VanHalen1995 (palette).bin" -fullpalette -exit


cd ..
folder2c bank13 bank13 13

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK13 bank13.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts