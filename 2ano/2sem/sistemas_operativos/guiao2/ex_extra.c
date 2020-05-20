#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */



int has_num(int** m, int line, int line_size, int num){
	int i;
	for(i = 0; i < line_size && m[line][i] != num; i++);
	if(m[line][i] == num)
		return 1;
	return 0;
}

int ** matriz_rnd(int l, int c){
	int i, j;

	int **m = (int**) malloc(sizeof(int*) * l);
	for(i = 0; i < l; i++)
		m[i] = (int*) malloc(sizeof(int) * c);


	for(i = 0; i < l; i++)
		for(j = 0; j < c; j++)
			m[i][j] = rand() % 10;	

	return m;
}


int main(int argc, char const *argv[]){
	int fd_matrix, i, l, c, f = 0, num, status;
	pid_t aux;
	int ** matriz;

	if(argc < 4)
		return 1;	

	l = atoi(argv[1]);
	c = atoi(argv[2]);
	num = atoi(argv[3]);

	matriz = matriz_rnd(l,c);

	if((fd_matrix = open("matrix_rnd.txt", O_CREAT | O_RDWR | O_TRUNC, 0777)) <= 0){
		perror("Error opening or creating the file.");
		f = 1;
	}
	if(!f && write(fd_matrix, matriz, sizeof(int) * c * l) < sizeof(int) * c * l){
		perror("Error in writing in file.");
		close(fd_matrix);
		f = 1;
	}

	for(i = 0; i < l && !f; i++){
		aux = fork();
		if(aux == 0){
			_exit(has_num(matriz, i, c, num));
		}
		else
			if(aux == wait(&status) && WIFEXITED(status)){
				if(f = WEXITSTATUS(status))
					printf("Number found in matrix\n");
			}
			else
				printf("Error in process #%d\n", i);
	}
	if(fd_matrix >= 0)
		close(fd_matrix);
	free(matriz);

	return 0;
}


