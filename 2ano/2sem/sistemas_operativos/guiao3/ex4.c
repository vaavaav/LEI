#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int ret;
    char *exec_arg[] = {"./ex3", "ls", "-l", NULL};

    ret = execvp(exec_arg[0],  exec_arg - 1);
    perror("Erro: "); /* tudo abaixo do exec supostamente não funciona */

    return 0;
}
