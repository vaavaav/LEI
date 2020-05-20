#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int fd_server, status = 0;
    pid_t pid;

    /* Abrir fd de leitura do servidor */
     if((fd_server = open("svpipe", O_WRONLY)) < 0){
        perror("open");
        exit(1);
    }

    /* Receber mensagens de clientes */
    if((pid = fork()) == 0){
        dup2(fd_server, 1); /* Ler dos clientes */
        execlp("cat", "cat", NULL);
        _exit(1);
    }
    close(fd_server);

    wait(&status);

    return 0;
}