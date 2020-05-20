#ifndef LN_H
#define LN_H

#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>

/** @brief Função que lista as linhas lidas no stdin*/
int my_nl();

#endif 