:: bank50
@echo off

cd ..
cd banks
folder2c bank50 bank50 50

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK50 bank50.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
