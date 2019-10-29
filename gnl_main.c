#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h>
#include<stdbool.h>
#include "gnl_cpy/get_next_line.h"
#include<string.h>
#include<time.h>
int  fd;
int  fd_seg;
char *str_out;
int retu = 1;
pid_t pid;
bool has_segfault_ft;
bool ok;
# define TEST_SEGFAULT(func) do { \
	if ((pid = fork()) < 0) \
		exit(EXIT_FAILURE); \
	if (pid == 0) { \
		do { func } while(0); \
		exit(EXIT_SUCCESS); \
	} else { \
		wait(&pid); \
		has_segfault_ft = WIFSIGNALED(pid); \
	} \
} while(0)

#define TESTER_gnl(fileName,expected,exp_return,msg,ln) do{\
        if (fd == -1)\
            printf("\033[1;31mError in Opening file!!\033[0m\n");\
        else{\
        TEST_SEGFAULT(get_next_line(fd_seg, &str_out););\
        if (has_segfault_ft)\
        {\
            printf("\033[0;31m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%d\n","SEGFAULT",msg,BUFFER_SIZE);\
            return 0377;\
        }\
        else{\
            if (fd == -1)\
                printf("\033[1;31mError in Opening file!!\033[0m\n");\
            else{\
                start =  clock();\
                retu = get_next_line(fd, &str_out);\
                time += ((double)clock() - start) / (double)CLOCKS_PER_SEC;\
                if (!str_out || !expected)\
                {\
                    printf("\033[0;31m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%-15dOUT: \"%s\"\tEXPECTED : \"%s\"\t\t AT_LINE : %d\n","KO IN LINE",msg,BUFFER_SIZE,str_out,expected,ln);\
                    return 0377;\
                }\
                if(strcmp(str_out,expected))\
                {\
                    printf("\033[0;31m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%-15dOUT: \"%s\"\tEXPECTED : \"%s\"\t\t AT_LINE : %d\n","KO IN LINE",msg,BUFFER_SIZE,str_out,expected,ln);\
                    return 0377;\
                }\
                if (retu != exp_return)\
                {\
                   printf("\033[0;31m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%-15dOUT : %d\tEXPECTED : %d \t\tAT LINE : %d\n","KO IN RETURN",msg,BUFFER_SIZE,retu,exp_return,ln);\
                    return 0377;\
                }\
            }\
        }\
        }}while(0)

int count_line(char *s)
{
    FILE *fp = fopen(s,"r");
    char *str = malloc(1);
    size_t i;
    int count = 0;
    while(getline(&str,&i,fp) >= 0)
        count++;
    return count + 1;
}

int main(int ac, char **av) 
{   
    ac = 0;
    int n_time = atoi(av[2]);
    double time = 0;
    // OPEN THE FILE
    FILE *fp = fopen(av[1], "r"); 
    fd = open(av[1],O_RDONLY);
    fd_seg = open(av[1],O_RDONLY);
    if (fp == NULL || fd < 0 || fd_seg < 0) { 
        printf("\033[1;31mCould not open file %s\n", av[1]); 
        return 0; 
    } 
    if (n_time <= 0)
        n_time = count_line(av[1]);
    char *buffer_expected = NULL;
    size_t buffer_size = 0;
    int return_expected = 0;
    int line_number = 1;
    clock_t start;
    bool whatever;
    for (int i = 1; i <= n_time ; i++)
    {
        whatever = false;
        return_expected = getline(&buffer_expected, &buffer_size, fp);
        if(buffer_expected[return_expected - 1] == '\n')
        {
            buffer_expected[return_expected - 1] = 0;
            whatever = true;
        }
        return_expected = return_expected  > 0 || whatever ? 1 : 0;
        return_expected = (i == n_time - 1 && !whatever)  ? 0 : return_expected;
        TESTER_gnl(av[1], buffer_expected, return_expected,av[3],line_number);
        line_number++;
        if (time > 1)
        {
            printf("\033[0;31m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%d\n","TIME OUT",av[3],BUFFER_SIZE);
            return 0377;
        }    
    }
    printf("\033[0;32m%-15s\033[0;33mFILE_NAME :\033[0;34m %-50s \033[0;33mBUFFER_SIZE : \033[1;0m%-18d\033[0;33mTime :\e[1;0m %lfs\n","OK",av[3],BUFFER_SIZE,time);
    return 0;
  
    
}
