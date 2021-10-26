set -ex
gcc -g main.c list.c -o main.bin
gdb main.bin