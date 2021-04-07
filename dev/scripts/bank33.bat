:: bank33
@echo off

cd ..
cd banks
folder2c bank33 bank33 33

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK33 bank33.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
