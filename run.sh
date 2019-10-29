make cp_f
gcc -Wall -Werror -Wextra compi_main.c gnl_cpy/*.c > cmp_error.txt -D BUFFER_SIZE=50 2>&1
check=$(cat cmp_error.txt |  wc -l | tr -d " ")
if [ $check -gt 0 ]; then
    gcc -Wall -Werror -Wextra compi_main.c gnl_cpy/*.c -D BUFFER_SIZE=50
else
    ./a.out
    rm ./a.out
    make kk
fi
rm -f cmp_error.txt
