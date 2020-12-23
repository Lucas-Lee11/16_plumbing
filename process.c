#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char const *argv[]) {

    int random = open("/dev/random", O_RDONLY);
    int num [1];
    read(random, num, 4);

    int fd = open("./temp", O_RDWR);

    char buffer[1024], *c = buffer;
    read(fd, buffer, sizeof(buffer));

    while(*c){
        *c += *num % 10;
        c++;
    }
    *(c-1) = '\0';

    write(fd, buffer, sizeof(buffer));
    close(fd);

    return 0;
}
