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

    printf("Chooses a random number between -9 and 9, then adds that much to each character in the string by that amount\n");

    while(1){
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);

        char * file = "./temp";
        mkfifo(file, 0666);

        int fd = open(file, O_WRONLY);
        write(fd, buffer, sizeof(buffer));

        close(fd);

        char * file2 = "./temp2";
        int fd2 = open(file2, O_RDONLY);

        char out[1024];
        read(fd, out, sizeof(out));

        printf("Shuffled Output: %s\n", out);

        close(fd2);

    }

    return 0;
}
