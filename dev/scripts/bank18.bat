:: bank18
@echo off

cd ..
cd banks
folder2c bank18 bank18 18

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK18 bank18.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
