#include "pessoas.h"

typedef struct pessoa{
	char name[100];
	int age;
} person;


Person person_init(char* name, int age){
	Person new = malloc(sizeof(person));
	//new->name = malloc(sizeof(char) *(strlen(name) + 1));
	strcpy(new->name, name);
	strcat(new->name, "\0");
	new->age = age;

	return new;
}

void person_free(Person p){
	if(p != NULL){
		//free(p->name);
		free(p);
	}
}

void person_printf(Person p){
	if(p != NULL)
		printf("%s : %d", p->name, p->age);
}


int person_write(int fd_people, Person p){
	ssize_t s_read;
	int i = 0;
	person aux;

	if(fd_people >= 0){
		while((s_read = read(fd_people, &aux, sizeof(person))) > 0){
			printf("%d | ", i);
			person_printf(&aux);
			printf("\n");
			i++;
		}
		if(s_read == -1){
			perror("Error while reading.");
			return -1;
		}
		if(write(fd_people, p, sizeof(person)) == -1)
			return -1;
		return i;
	}
	else return -1;
}

int person_update(int fd_people, int index, int n_age){
	person aux;

	if(fd_people >= 0){
		if(lseek(fd_people, index*sizeof(person), SEEK_SET) == -1)
			return -1;
		if(read(fd_people, &aux, sizeof(person)) == -1)
			return -1;
		aux.age = n_age;
		if(lseek(fd_people, index*sizeof(person), SEEK_SET) == -1)
			return -1;

		if(write(fd_people, &aux, sizeof(person)) == -1)
			return -1;
		return index;
	}
	else
		return -1;
}

