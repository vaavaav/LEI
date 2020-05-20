#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>


int main(int const argc, char const **argv){
	int i, status;
	pid_t pids[10], pid; 

	for(i = 0; i < 10; i++){
		pid = fork();
		if(pid == 0){
			printf("I'm son and my PID is: %d. My parent's PID is: %d\n", getpid(), getppid());
			_exit(i+1);
		}else
			pids[i] = pid;
	}
	for(i = 0; i < 10; i++){
		pid = waitpid(pids[i], &status, 0);
		if(pid == pids[i] && WIFEXITED(status))
			printf("Son #%d exited with: %d\n", i, WEXITSTATUS(status));
		else
			printf("Something went wrong with process #%d", i);
	}
	return 0;
}

