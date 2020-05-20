#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(execvp("echo", argv))
        perror("Erro: ");

    return 0;
}