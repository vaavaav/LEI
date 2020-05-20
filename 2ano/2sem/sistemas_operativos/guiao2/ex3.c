#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>


int main(int const argc, char const **argv){
	int i, status;
	pid_t pid; 

	for(i = 0; i < 10; i++){
		pid = fork();
		if(pid == 0){
			printf("I'm son and my PID is: %d. My parent's PID is: %d\n", getpid(), getppid());
			_exit(i+1);
		}else{
			if(pid == wait(&status) && WIFEXITED(status))
				printf("I'm parent and last son returned: %d\n", WEXITSTATUS(status));
			else
				perror("Error exiting son.\n");
		}
	}
}


