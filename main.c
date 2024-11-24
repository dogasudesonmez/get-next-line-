#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("doga.txt", O_CREAT | O_RDONLY, 0644);

    printf("%s", get_next_line(fd));
}