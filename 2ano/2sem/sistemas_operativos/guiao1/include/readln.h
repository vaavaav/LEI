#ifndef READLN_H
#define READLN_H

#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>

/** @brief Função que lê uma linha (i.e. sequência terminada por \n). */
ssize_t readln(int fd, char *line, size_t size);

#endif 