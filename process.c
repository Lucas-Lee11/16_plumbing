#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

    while(1){
        int random = open("/dev/random", O_RDONLY);
        int num [1];
        read(random, num, 4);

        int fd = open("./temp", O_RDONLY);

        char buffer[1024], *c = buffer;
        read(fd, buffer, sizeof(buffer));

        close(fd);

        while(*c){
            *c += *num % 10;
            c++;
        }
        *(c-1) = '\0';

        fd = open("./temp2", O_WRONLY);

        write(fd, buffer, sizeof(buffer));
        close(fd);
    }



    return 0;
}
