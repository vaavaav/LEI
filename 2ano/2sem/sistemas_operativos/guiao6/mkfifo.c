#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* agrv[]){
    int fd;

    if(mkfifo("fifo", 0666) < 0){
        perror("mkfifo");
    }

    return 0;

}