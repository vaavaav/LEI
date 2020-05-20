#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 13
char* msg1 = "Hello world!"; 
int main(){

    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
  
    if (pipe(p) < 0) 
        exit(1); 
  
    /* continued */
    if ((pid = fork()) > 0) { 
        write(p[1], msg1, MSGSIZE); 
        wait(NULL);
    } 
    else { 
        read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf); 
        exit(2); 
    } 

    printf("%s\n", inbuf); /* isto é no processo pai por isso o array está vazio */
    return 0; 
}