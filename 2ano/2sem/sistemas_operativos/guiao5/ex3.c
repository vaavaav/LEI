#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd[2];
    pid_t pid;

    if(pipe(fd) == 0){
        if((pid = fork()) == 0){ /* Processo filho */
            close(fd[0]);
            close(fd[1]);
            execlp("wc", "wc" ,(char*) NULL);
            _exit(0);
        }
        else{ /* Processo pai */
            close(fd[0]);
            dup2(0,fd[1]);
            close(fd[1]);
            wait(NULL);
        }
    }


}