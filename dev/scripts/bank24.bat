:: bank24
@echo off

cd ..
cd banks
folder2c bank24 bank24 24

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK24 bank24.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
