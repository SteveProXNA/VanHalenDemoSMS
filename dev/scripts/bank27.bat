:: bank27
@echo off

cd ..
cd banks
folder2c bank27 bank27 27

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK27 bank27.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
