#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int ret;
    char *exec_arg[] = {"ls", "-l", NULL};

    ret = execvp("ls", exec_arg);
    perror("Erro: "); /* tudo abaixo do exec supostamente não funciona */

    return 0;
}
