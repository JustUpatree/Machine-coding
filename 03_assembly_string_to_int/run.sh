set -ex
nasm -f elf64 main.asm -o main.o
ld main.o -o main.bin
./main.bin