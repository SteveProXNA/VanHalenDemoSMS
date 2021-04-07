:: bank49
@echo off

cd ..
cd banks
folder2c bank49 bank49 49

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK49 bank49.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
