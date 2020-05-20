#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int my_system(char *commands){
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
        if(i >= 1)
            _exit(execvp(aux[0], aux));
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

int main(int argc, char *argv[]){
    char *str = "cp ex6.c -t ..";
    return my_system(str);
}