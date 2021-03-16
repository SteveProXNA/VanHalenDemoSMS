@echo off
clear

if [ -a main.o ]
then
    rm main.o
fi

echo Compile
wla-z80 -o main.o main.asm 

echo [objects] > linkfile
echo main.o >> linkfile

echo Link
wlalink linkfile output.sms

if [ -a main.o ]
then
    rm main.o
fi

echo Run
java -jar ~/SEGA/Emulicious/Emulicious.jar output.sms 2> /dev/null
#output.sms