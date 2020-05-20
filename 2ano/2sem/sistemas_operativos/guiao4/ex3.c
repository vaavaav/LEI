
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>


#define input_path "/etc/passwd"

int main(int argc, char *argv[]){
	int res = 0;
	int fork_ret, status;


	int i_fd = open(input_path, O_RDONLY);
	int o_fd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	int e_fd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);

	res = dup2(i_fd,0);
	res = dup2(o_fd,1);
	res = dup2(e_fd,2);

	close(i_fd);
	close(o_fd);
	close(e_fd);

	if((fork_ret = fork()) == 0)
        _exit(execlp("wc", input_path , (char*) NULL));
	else{
		printf("PID pai: %d\n", getpid());
		if(fork_ret == wait(&status) && WIFEXITED(status))
			printf("O filho retornou %d\n", WEXITSTATUS(status));
		else{
			printf("O filho não terminou\n");
		}
	}

	return 0;
}