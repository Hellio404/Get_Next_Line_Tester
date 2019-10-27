#include "gnl_cpy/get_next_line.h"
#include<stdio.h> 
#include<fcntl.h> 
int main()
{
	char *str;
	int fd = open("test/normal.txt", O_RDONLY);
	if (fd < 0) { 
        printf("\033[1;31mCould not open file\n"); 
        return 0377; 
    }
	while(get_next_line(fd, &str))
		free(str);
	free(str);
	fd = open("test/long_line.txt", O_RDONLY);
	if (fd < 0) { 
        printf("\033[1;31mCould not open file\n"); 
        return 0377; 
    }
	while(get_next_line(fd, &str))
		free(str);
	free(str);
}