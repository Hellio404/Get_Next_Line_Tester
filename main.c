#include <stdio.h>
#include <stdlib.h>

#define TEST(buff_size,files,files_nbr,nbt,ok_msg)do{\
    sprintf(tmp,"gcc gnl_cpy/*.c gnl_main.c -D BUFFER_SIZE=%d -o run_out", buff_size);\
    system(tmp);\
    for (int  i = 0; i < files_nbr; i++)\
    {\
        sprintf(tmp,"./run_out \"%s\" %d \"%s\"", files[i],nbt, ok_msg[i]);\
        system(tmp);\
    }\
    }while(0)\

int size_of_arr(char **p)
{
    int i = 0;
    while(p[i])
        i++;
    return (i);
}

int main()
{
    char tmp[255];
    /*1 --> BUFFER_SIZE,  2 --> FILE_PATH,  3  --> NUMBER OF LINE TO READ (0 TO READ TO THE END),  4 -->  DESCRIPTION*/
    char *tests[] = {"test/normal.txt", "test/64bit_paragraph.txt", "test/64bit_line.txt", "test/long_line.txt", "test/empty.txt", "test/fewchar_perline.txt", "test/only_newline.txt",NULL};
    //char *desri[] = {"Normal FILE 10k", "64 character per line paragraph 6k", "64 character line", "10K character line", "empty file", "Short Line < 5 character","Only new lines file",NULL};
    char **desri = tests;
    int size = size_of_arr(tests);
    TEST(1,tests,size, 0,desri);
    TEST(64,tests,size, 0,desri);
    TEST(63,tests,size, 0,desri);
    TEST(65,tests,size, 0,desri);
    TEST(100,tests,size, 0,desri);
    TEST(9999,tests,size, 0,desri);
    TEST(100000,tests,size, 0,desri);
    TEST(1000000000,tests,size, 0,desri);
    // CHECK THE MEMORY LEAK
    setbuf(stdout, NULL);
    printf("\nMEMORY LEAK TEST : ");
    system("gcc gnl_cpy/*.c mem_check_main.c -D BUFFER_SIZE=500 -o mem_check && bash memory_leak.sh");
    printf("\nCHECK READING FORM STDIN : ");
    system("gcc gnl_cpy/*.c main_stdin.c -D BUFFER_SIZE=500 -o std_check && bash stdin_check.sh");
    printf("\nCHECK ONE STATIC VARIABLE :");
    system("bash ./bounus_one_static.sh");
 
    
}
