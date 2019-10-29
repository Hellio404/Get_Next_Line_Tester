#include "gnl_cpy/get_next_line.h"
#include <stdio.h>
int main()
{
    char *line;
    int rt = get_next_line(45,&line);
    if (rt != -1)
        printf("\e[0;31mReture KO when given a random invalid fd OUT : %2d Expected -1\n\n",rt);
    else
        printf("\e[0;32mReture OK when given a random invalid fd\n\n");
    return (0);
}