:: bank58
@echo off

cd ..
cd banks
folder2c bank58 bank58 58

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK58 bank58.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
