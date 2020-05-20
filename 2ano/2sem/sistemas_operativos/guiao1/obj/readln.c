#include "readln.h"

#define BUFFER_SIZE 100


ssize_t readln(int fd, char *line, size_t size){
	char buf[BUFFER_SIZE];
	int off_set = (fd > 0) - 1, r = 0, i, f = 0;

	if(!off_set)
		while(!f && (r = read(fd, buf, BUFFER_SIZE)) > 0)
			for(i = 0; i < r && !f; i++){
				line[off_set++] = buf[i];
				f = buf[i] == '\n' || off_set > size; 
			}

	return off_set;
}
/*Help: (open) http://codewiki.wikidot.com/c:system-calls:open
*		(read) http://codewiki.wikidot.com/c:system-calls:read
*		(write) http://codewiki.wikidot.com/c:system-calls:write
*/
