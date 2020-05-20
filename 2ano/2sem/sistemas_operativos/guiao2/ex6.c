#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 10
#define COLUNAS 100

int MATRIZ[LINHAS][COLUNAS] = {0};

int has_num(int linha, int num){
	int i;
	for(i = 0; i < COLUNAS && MATRIZ[linha][i] != num; i++);
	if(MATRIZ[linha][i] == num)
		return 1;
	return 0;
}

int main(int argc, char const *argv[]){
	int i, j, num, status;
	pid_t aux; 

	//num to be search given in argv[1]

	if(argc < 2)
		return 1;

	num = atoi(argv[1]);


	//Randomize positions with random numbers

		MATRIZ[rand() %LINHAS][rand() % COLUNAS] =  1;

	// Print matrix
	for(i = 0; i < LINHAS; i++){
		for(j = 0; j < COLUNAS; j++)
			printf("%d ", MATRIZ[i][j]);
		printf("\n");
	}

	// processes
	for(i = 0; i < LINHAS; i++){
		aux = fork();

		if(aux == 0)
			_exit(has_num(i, num));
		else{
			if(aux == wait(&status) && WIFEXITED(status)){
				if(WEXITSTATUS(status)){
					printf("Number found!\n");
					return 0;
				}
			}
			else
				printf("Something went wrong with process %d.\n",i);
		}
	}


	return 0;
}


