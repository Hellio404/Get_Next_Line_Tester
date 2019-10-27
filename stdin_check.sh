
input="aaaaaaaaaafadksjfkdlasjfkladsjfkljdasklfjdaklsfjklgjhbfasrkl;fds issjkafdkkashfadsfkkajfkldsajfjkladsjf fadsfdasf"
output=$(echo "$input" | ./std_check)
echo "#include<stdio.h>
	int main(int argc,char **argv){printf(\"\e[1;%sm\t%s\n\e[0m\",argv[1],argv[2]);}" > msg.c
	gcc msg.c -o msg_out
if [ "$input" = "$output" ]; then
	./msg_out 32 "OK"
else 
	./msg_out 31 "KO"
fi
rm -f std_check msg_out msg.c
