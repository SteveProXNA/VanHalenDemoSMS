:: bank30
@echo off

cd ..
cd banks
folder2c bank30 bank30 30

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK30 bank30.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
