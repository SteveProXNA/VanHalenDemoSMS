@echo off
REM gfx		Commonly used gfx	not banked

cd ..
cd ..
cd gfx

:: Tiles
bmp2tile.exe raw\font.bmp -savetiles "font (tiles).psgcompr" -removedupes -tileoffset 0 -savetilemap "font (tilemap).bin" -savepalette "font (palette).bin" -exit


:: Sprites
bmp2tile.exe raw\cursor.bmp -savetiles "cursor (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "cursor (palette).bin" -fullpalette  -spritepalette -exit


cd ..\dev

folder2c ..\gfx gfx

sdcc --debug -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

::cd ..
cd scripts