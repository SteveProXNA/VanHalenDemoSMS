:: bank53
@echo off

cd ..
cd banks
folder2c bank53 bank53 53

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK53 bank53.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
