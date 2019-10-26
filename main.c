#include <stdio.h>
#include <stdlib.h>

#define TEST(buff_size,file,nbt,ok_msg)do{\
    sprintf(tmp,"gcc gnl/*.c gnl_main.c -D BUFFER_SIZE=%d -o run_out", buff_size);\
    system(tmp);\
    sprintf(tmp,"./run_out \"%s\" %d \"%s\"", file,nbt, ok_msg);\
    system(tmp);\
    }while(0)\

int main()
{
    char tmp[255];
    /*1 --> BUFFER_SIZE,  2 --> FILE_PATH,  3  --> NUMBER OF LINE TO READ (0 TO READ TO THE END),  4 -->  DESCRIPTION*/

    
    TEST(1,"test/normal.txt",0,"Normal FILE 10k");
    TEST(4,"test/normal.txt",0,"Normal FILE 10k");
    TEST(9999,"test/normal.txt",0,"Normal FILE 10k");
    TEST(100000000,"test/normal.txt",0,"Normal FILE 10k");
    TEST(1000000000,"test/normal.txt",0,"Normal FILE 10k");
    TEST(1,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(4,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(9999,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(100000000,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(1000000000,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(100,"test/64bit_paragraph.txt",0,"64 character per line paragraph 6k");
    TEST(64,"test/64bit_line.txt",0,"64 character line");
    TEST(63,"test/64bit_line.txt",0,"64 character line");
    TEST(65,"test/64bit_line.txt",0,"64 character line");
    TEST(10,"test/long_line.txt",0,"10K character line");
    TEST(1000,"test/long_line.txt",0,"10K character line");
    TEST(100000000,"test/long_line.txt",0,"10K character line");
    TEST(1000000000,"test/long_line.txt",0,"10K character line");
    TEST(1,"test/empty.txt",0,"empty file");
    TEST(100000000,"test/empty.txt",0,"empty file");
    TEST(1,"test/fewchar_perline.txt",0,"Short Line < 5 character");
    TEST(1000,"test/fewchar_perline.txt",0,"Short Line < 5 character");
    TEST(100000000,"test/fewchar_perline.txt",0,"Short Line < 5 character");
    TEST(1000000000,"test/fewchar_perline.txt",0,"Short Line < 5 character");
    TEST(250,"test/bar.txt",2000,"Read 2k Lines from bar.txt");
    TEST(100000,"test/bar.txt",2000,"Read 2k Lines from bar.txt");
    TEST(1000000000,"test/bar.txt",2000,"Read 2k Lines from bar.txt");
    TEST(1,"test/only_newline.txt",0,"Only new lines file");
    TEST(100,"test/only_newline.txt",0,"Only new lines file");
    TEST(1000000000,"test/only_newline.txt",0,"Only new lines file");

    
}
