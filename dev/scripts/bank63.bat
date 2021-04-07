:: bank63
@echo off

cd ..
cd banks
folder2c bank63 bank63 63

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK63 bank63.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
