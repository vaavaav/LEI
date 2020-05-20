
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){
	int res = 0, n_lines = 10, i, j;
	char buffer, line[BUF_SIZE];
	int fork_ret, status;

	setbuf(stdout,NULL); //desativar o buff do stdout

	int i_fd = open("/etc/passwd", O_RDONLY);
	int o_fd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	int e_fd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);

	res = dup2(i_fd,0);
	res = dup2(o_fd,1);
	res = dup2(e_fd,2);

	close(i_fd);
	close(o_fd);
	close(e_fd);

	if((fork_ret = fork()) == 0){
		printf("PID filho: %d,n", getpid());

		for(j = n_lines; j > 0; j--){
            for(i = 0; i < BUF_SIZE && read(0, &buffer, 1) != 0 && (line[i] = buffer) != '\n'; i++);
			if(i != write(1,line,i)) _exit(-1);
			if(i != write(2,line,i)) _exit(-2);
		}
		_exit(0);
	}
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