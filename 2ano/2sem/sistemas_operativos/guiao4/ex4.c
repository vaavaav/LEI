#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    int i = 1, fd_input, fd_output, fork_ret, status;
    

    if(i + 1 < argc && strcmp("-i", argv[i]) == 0){
        fd_input = open(argv[++i], O_RDONLY);
        dup2(fd_input, 0);
        close(fd_input);
        i++;
    }
    if(i + 1 < argc && strcmp("-o", argv[i]) == 0){
        fd_output = open(argv[++i], O_CREAT | O_TRUNC | O_WRONLY, 0777);
        dup2(fd_output, 1);
        close(fd_output);
        i++;
    }

    if((fork_ret = fork()) == 0)
        _exit(execvp(argv[i], argv + i));
    else
        if(fork_ret == wait(&status) && WIFEXITED(status))
            return WEXITSTATUS(status); 

    return 0;

}