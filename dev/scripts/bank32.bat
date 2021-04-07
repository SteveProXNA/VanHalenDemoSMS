:: bank32
@echo off

cd ..
cd banks
folder2c bank32 bank32 32

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK32 bank32.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
