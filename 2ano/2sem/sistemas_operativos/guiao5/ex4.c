#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_system(int in, int out, char *commands){
    pid_t fork_ret;
    int status, buf_size = 1, i = 0, r = -1;
    char copy[200], **aux = malloc(sizeof(char*) * buf_size);
    

    strcpy(copy, commands);
    aux[0] = strtok(copy, " ");

    while(aux[i] != NULL){
        if(++i >= buf_size)
            aux = realloc(aux, (++buf_size) * sizeof(char*));
        aux[i] = strtok(NULL, " ");
    }

    if((fork_ret = fork()) == 0){
        if(i >= 1){
            dup2(in,0);
            dup2(out,1);
            _exit(execvp(aux[0], aux));
        }
        else
            _exit(0);
    }
    else{
        if(fork_ret == wait(&status) && WIFEXITED(status))
            r = WEXITSTATUS(status);
        else
            perror("Error in fork\n");
    }
    free(aux);
    return r;
}


int main(){
    char command[] =  "ls /etc | wc -l";
    int fd[2], i, n_commands = 1, n_parts = 0, in = 0;
    char *token_c;
    char **commands, copy[20], r[2] = "|";

    commands = malloc(sizeof(char*) * n_commands);

    token_c = strtok(command, r);
    for(i = 0; token_c != NULL; i++){
        if(i >= n_commands)
            commands = realloc(commands, ++n_commands);
        commands[i] = token_c;
        token_c = strtok(NULL, r);

        printf("%s\n",commands[i]);
    }

    if(n_commands == 1){
        my_system(0, 1, commands[0]);
    }
    else
        if(n_commands > 1){
            for(i = 0; i < n_commands - 1; i++){
                pipe(fd);
                my_system(in, fd[1], commands[i]);
                close(fd[1]);
                in = fd[0];
            }
            my_system(fd[0], 1, commands[i]);
            close(fd[0]);
        }



    return 0;

}
