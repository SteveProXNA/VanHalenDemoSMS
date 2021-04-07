:: bank57
@echo off

cd ..
cd banks
folder2c bank57 bank57 57

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK57 bank57.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
