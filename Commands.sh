#! /bin/bash
echo Compiling ...
bcc -ansi -c -o kernel.o kernel.c
echo linking ...
ld86 -o kernel -d kernel.o kernel_asm.o functions.o
echo transfering ...
dd if=kernel of=floppya.img bs=512 conv=notrunc 
echo running ...
bochs -f opsys.bxrc
