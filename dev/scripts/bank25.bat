:: bank25
@echo off

cd ..
cd banks
folder2c bank25 bank25 25

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK25 bank25.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
