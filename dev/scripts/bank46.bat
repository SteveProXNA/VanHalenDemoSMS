:: bank46
@echo off

cd ..
cd banks
folder2c bank46 bank46 46

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK46 bank46.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
