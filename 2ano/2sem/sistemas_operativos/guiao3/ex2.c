#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    int ret, status;
    char *exec_arg[] = {"ls", "-l", NULL};
    

    if(fork() == 0)
        _exit(execvp("ls", exec_arg));
    else
        if(wait(&status) && WIFEXITED(status))
            return WEXITSTATUS(status);
    
    return 0;
}
