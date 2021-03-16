@echo off
REM albums

cd ..
cd banks
cd bank9


:: Tiles
bmp2tile.exe "raw\VanHalen1984.bmp" -savetiles "VanHalen1984 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1984 (tilemap).stmcompr" -savepalette "VanHalen1984 (palette).bin" -fullpalette -exit


cd ..
folder2c bank9 bank9 9

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK9 bank9.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts