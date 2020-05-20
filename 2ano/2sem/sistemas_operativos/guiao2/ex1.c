#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>	/* chamadas wait*() e macros relacionadas */
#include <stdio.h>

int main(int const argc, char const **argv){
	printf("My parent PID is: %d\n", getppid());
	return 0;
}