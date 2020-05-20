#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>


int main(int const argc, char const **argv){
	int status;
	pid_t const pid = fork();

	if(pid == 0){
		printf("I'm son and my PID is: %d\n", getpid());
		printf("My parent has PID: %d\n", getppid());
		_exit(0);
	}
	else{
		printf("I'm parent and my PID is: %d\n", getpid());
		printf("My son has PID: %d\n", pid);
	}
	if(pid == waitpid(pid, &status, 0) && WIFEXITED(status))
			return(WEXITSTATUS(status));
}