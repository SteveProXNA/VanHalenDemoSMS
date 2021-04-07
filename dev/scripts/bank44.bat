:: bank44
@echo off

cd ..
cd banks
folder2c bank44 bank44 44

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK44 bank44.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
