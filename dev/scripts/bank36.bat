:: bank36
@echo off

cd ..
cd banks
folder2c bank36 bank36 36

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK36 bank36.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
