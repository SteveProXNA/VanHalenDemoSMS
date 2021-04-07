:: bank20
@echo off

cd ..
cd banks
folder2c bank20 bank20 20

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK20 bank20.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
