gcc xxd_cleaner.c -o xxd_cleaner
cat main.mc | ./xxd_cleaner | xxd -r -p > main.bin
chmod +x main.bin 
./main.bin
