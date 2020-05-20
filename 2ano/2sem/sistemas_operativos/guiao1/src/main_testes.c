#include <sys/types.h>
#include <unistd.h>		/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>		/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ln.h"
#include "pessoas.h"


#define BUFFER_SIZE 100

int main(int argc, char **argv){
	int r, fd, i;
	//r = my_nl();
	char buf[BUFFER_SIZE];
	Person aux;

	if((fd = open("input/pessoas.txt", O_CREAT | O_RDWR, 0777)) == -1){
		perror("Error while opening.");
		return -1;
	}
	else{
		printf("%d\n",argc);
		if(strcmp(argv[1], "pessoas") == 0){
			if(argv[2][0] == '-'){
				switch(argv[2][1]){
					case 'i':
						aux = person_init(argv[3], strtol(argv[4], NULL, 10));
						i = person_write(fd, aux);
						printf("Registo %d\n", i);
						person_free(aux);
						break;
					case 'u':
						person_update(fd, strtol(argv[3], NULL, 10), strtol(argv[4], NULL, 10));
						break;

					default:
						break;

				}
			}
		}

	return r;
	}
}
/*Help: (open) http://codewiki.wikidot.com/c:system-calls:open
*		(read) http://codewiki.wikidot.com/c:system-calls:read
*		(write) http://codewiki.wikidot.com/c:system-calls:write
*/
