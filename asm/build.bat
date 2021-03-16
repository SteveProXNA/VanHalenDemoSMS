@echo off
cls

if exist main.o del main.o

echo Compile
wla-z80 -o main.o main.asm 

echo [objects] > linkfile
echo main.o >> linkfile

echo Link
wlalink linkfile output.sms

if exist output.sms.sym del output.sms.sym
if exist main.o del main.o

echo Run
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms
::output.sms

copy output.sms E:\GitHub\StevePro7\Z80test\05-Utils\BinaryFileXCompare\bin\Debug\input