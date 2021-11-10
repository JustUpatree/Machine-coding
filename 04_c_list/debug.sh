set -ex
gcc -Werror -g main.c sll.c -o main.bin
gdb main.bin