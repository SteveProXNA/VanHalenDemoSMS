@echo off
:: 1978

cd ..
cd banks

folder2c bank16 bank16 16

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK16 bank16.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts