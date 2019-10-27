num=$(cat gnl_cpy/*.c | grep  -G "^	static" | wc  -l | tr -d " ")
rm -rf  mem_check valgrind_out mem_check.dSYM
echo "#include<stdio.h>
	int main(int argc,char **argv){printf(\"\e[1;%sm\t%s\n\e[0m\",argv[1],argv[2]);}" > msg.c
gcc msg.c -o msg_out
if [ $num -eq 1 ]
then
	./msg_out 32 "OK"
else
	./msg_out 31 "KO"
fi

rm -f  msg_out msg.c
