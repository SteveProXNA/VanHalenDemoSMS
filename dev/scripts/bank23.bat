:: bank23
@echo off

cd ..
cd banks
folder2c bank23 bank23 23

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK23 bank23.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
