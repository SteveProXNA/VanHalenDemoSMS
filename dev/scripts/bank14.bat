@echo off
REM title

cd ..
cd banks
cd bank14


:: Tiles
bmp2tile.exe "raw\VanHalen1998.bmp" -savetiles "VanHalen1998 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1998 (tilemap).stmcompr" -savepalette "VanHalen1998 (palette).bin" -fullpalette -exit


cd ..
folder2c bank14 bank14 14

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK14 bank14.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts