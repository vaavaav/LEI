#ifndef PESSOAS_H
#define PESSOAS_H

#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa *Person;

Person person_init(char* name, int age);

void person_free(Person p);

int person_write(int fd_people, Person p);

int person_update(int fd_people, int n_age, int index);

#endif 