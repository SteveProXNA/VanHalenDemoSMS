:: bank41
@echo off

cd ..
cd banks
folder2c bank41 bank41 41

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK41 bank41.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
