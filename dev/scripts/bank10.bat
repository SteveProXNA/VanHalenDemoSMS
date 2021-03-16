@echo off
REM albums

cd ..
cd banks
cd bank10


:: Tiles
bmp2tile.exe "raw\VanHalen1986.bmp" -savetiles "VanHalen1986 (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 0 -savetilemap "VanHalen1986 (tilemap).stmcompr" -savepalette "VanHalen1986 (palette).bin" -fullpalette -exit


cd ..
folder2c bank10 bank10 10

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK10 bank10.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts