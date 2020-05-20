#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int res = 0;
	int n_lines = 100;
	char buffer;
	char line[1024];
	int i = 0;
	int fork_ret, wait_ret, status;

	setbuf(stdout,NULL); //desativar o buff do stdout

	int i_fd = open("/etc/passwd", O_RDONLY);
	int o_fd = open("saida.txt", O_CREAT | O_WRONLY, 0777);
	int e_fd = open("erros.txt", O_CREAT | O_WRONLY, 0777);

	res = dup2(i_fd,0);
	res = dup2(o_fd,1);
	res = dup2(e_fd,2);

	close(i_fd);
	close(o_fd);
	close(e_fd);

	if((fork_ret = fork()) == 0){
		printf("PID filho: %d,n", getpid());
		sleep(2);

		while(n_lines > 0){
				while(read(0, &buffer, 1) != 0){
					line[i++] = buffer;
					if(buffer == '\n')
						break;
				}
				write(1,line,i);
				write(2,line,i);
				i = 0;
				n_lines--;
		}
		perror("Error: ");
		_exit(0);

	}
	else{
		printf("PID pai: %d\n", getpid());
		wait_ret = wait(&status);
		if(WIFEXITED(status)){
			printf("O filho retornou %d\n", WEXITSTATUS(status));
		}
		else{
			printf("O filho não terminou\n");
		}
	}
	return 0;
}