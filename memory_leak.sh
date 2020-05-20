valgrind ./mem_check > valgrind_out 2>&1
byts=$(cat valgrind_out | grep defin | cut -d : -f 2 | cut -d b  -f 1 | tr -d " " | tr -d ",")
check=$(cat valgrind_out | grep defin | wc -l| tr -d " ")
if [ $check -gt 0 ]
then
	rm -rf  mem_check valgrind_out mem_check.dSYM
	echo "#include<stdio.h>
	int main(int argc,char **argv){printf(\"\e[1;%sm\t%s\n\e[0m\",argv[1],argv[2]);}" > msg.c
	gcc msg.c -o msg_out
	if [ $byts -gt 0 ]
	then
		./msg_out 31 "MEMORY LEAK DETECTED!!!"
	else
		./msg_out 32 "NO NEMORY LEAK DETECTED"
	fi
	rm -rf msg.c msg_out
else
	echo "PLEASE INSTALL VALGRIND USING BREW FIRST"
fi
