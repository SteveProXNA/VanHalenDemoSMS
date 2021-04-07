:: bank19
@echo off

cd ..
cd banks
folder2c bank19 bank19 19

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK19 bank19.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
