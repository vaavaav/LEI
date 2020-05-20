#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */


#define BUFFER_SIZE 100

/** Função de cópia de um ficheiro para um certo caminho.
* 	Pressupõe-se que o path do caminho está em argv[1] e o path do target em argv[2].
*/
int my_cp(int argc, char **argv){
	int fd_origin, fd_target, off_set;		/* File Descriptor */
	char buffer[BUFFER_SIZE];

	if((fd_origin = open(argv[1], O_RDONLY)) >= 0){
		fd_target = open(argv[2], O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);

		while((off_set = read(fd_origin, buffer, sizeof(char)*BUFFER_SIZE)) > 0)
			write(fd_target, buffer, sizeof(char)*off_set);

		close(fd_target);
		close(fd_origin);
	}
	return 0;
}
/*Help: (open) http://codewiki.wikidot.com/c:system-calls:open
*		(read) http://codewiki.wikidot.com/c:system-calls:read
*		(write) http://codewiki.wikidot.com/c:system-calls:write
*/
