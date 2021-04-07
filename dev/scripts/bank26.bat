:: bank26
@echo off

cd ..
cd banks
folder2c bank26 bank26 26

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK26 bank26.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
