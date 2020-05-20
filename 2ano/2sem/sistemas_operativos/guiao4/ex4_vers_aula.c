#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int mysystem(char *command){
    int fork_ret, exec_ret, wait_ret, status, res;
    char *exec_args[20];
    char *string;
    int i = 0;

    string = strtok(command, " ");

    while(string != NULL){
        exec_args[i++] = string;
        string = strtok(NULL, " ");
    }

    exec_args[i] = NULL;


    fork_ret = fork();

    if(fork_ret == 0){
        exec_ret = execvp(exec_args[0], exec_args);
        _exit(0);
    }
    else{
        if(fork_ret != -1){
            wait_ret = wait(&status);
            if(WIFEXITED(status)){
                res = WEXITSTATUS(status);
            }
            else{
                res = -1;
            }
        }
        else
        {
            res = -1;
        }
    }
    return res;
}


int main(int argc, char *argv[]){
    int res = 0;
    int commandindex = 1;
    char command[1024];
    int ifd, ofd;
    setbuf(stdout,NULL);

    if(strcmp(argv[commandindex], "-i") == 0){
        ifd = open(argv[commandindex+1], O_RDONLY);
        res = dup2(ifd, 0);
        close(ifd);
        commandindex += 2;
    }

    if(strcmp(argv[commandindex], "-o") == 0){
        ofd = open(argv[commandindex + 1], O_CREAT | O_WRONLY, 0777);
        res = dup2(ofd,1);
        close(ofd);
        commandindex += 2;
    }

    while(commandindex < argc){
        strcat(command, argv[commandindex]);
        strcat(command, " ");
        commandindex++;
    }

    mysystem(command);
    return 0;
}