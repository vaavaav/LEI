#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    int i, status;
    pid_t children[argc - 1], pid;

    for(i = 0; i < argc - 1; i++){
        pid = fork();
        if(pid == 0)
            _exit(execl(argv[i + 1], argv[i + 1], (char*) NULL));
        else
            children[i] = pid; 
    }

    for(i = 0; i < argc - 1; i++){
        pid = children[i];
        if(pid ==  waitpid(pid, &status, 0) && WIFEXITED(status))
            if(WEXITSTATUS(status))
                perror("Error in process\n");
    }

    return 0;
}
