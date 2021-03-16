@echo off
REM albums

cd ..
cd banks
cd bank3


:: Tiles
bmp2tile.exe "raw\VanHalenTitleGap.bmp" -savetiles "VanHalenTitleGap (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 64 -savetilemap "VanHalenTitleGap (tilemap).stmcompr" -savepalette "VanHalenTitleGap (palette).bin" -fullpalette -exit
bmp2tile.exe "raw\VanHalenTitleTop.bmp" -savetiles "VanHalenTitleTop (tiles).psgcompr" -removedupes -mirror -planar -tileoffset 64 -savetilemap "VanHalenTitleTop (tilemap).stmcompr" -savepalette "VanHalenTitleTop (palette).bin" -fullpalette -exit


cd ..
folder2c bank3 bank3 3

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts