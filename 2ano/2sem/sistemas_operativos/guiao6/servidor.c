#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int fd_log, fd_server, status = 0;
    pid_t pid;
    /* Abrir ficheiro de logs*/
    if((fd_log = open("log", O_CREAT | O_WRONLY)) < 0){
        perror("open of log");
        exit(1);
    }

    /* Abrir fd de leitura do servidor */
     if((fd_server = open("svpipe", O_RDONLY)) < 0){
        perror("open of svpipe");
        exit(1);
    }

    /* Receber mensagens de clientes */
    if((pid = fork()) == 0){
        dup2(fd_log,1); /* Escrever no log */
        dup2(fd_server, 0); /* Ler dos clientes */
        execlp("cat", "cat", NULL);
        _exit(1);
    }

    close(fd_log);
    close(fd_server);

    wait(&status);

    return 0;
}