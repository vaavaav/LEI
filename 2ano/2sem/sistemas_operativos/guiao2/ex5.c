#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>


void son_fork(int i){
	pid_t pid = fork();
	int status;
	while(i > 0){
		if(pid == 0){
			printf("I'm son and my PID is: %d. My parent's PID is: %d\n", getpid(), getppid());
			pid = fork();
			i--;
		}
		else{
			wait(&status);
			_exit(0);
		}
	}
}


int main(int const argc, char const **argv){
	int i, status;
	
	son_fork(10);

	return 0;
}


