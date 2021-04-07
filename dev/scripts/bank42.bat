:: bank42
@echo off

cd ..
cd banks
folder2c bank42 bank42 42

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK42 bank42.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
