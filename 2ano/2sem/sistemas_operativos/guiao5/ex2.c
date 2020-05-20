#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 15
char* msg1 = "Hello world!#1";
char* msg2 = "Hello world!#2";
char* msg3 = "Hello world!#3"; 
int main(){

    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
  
    if (pipe(p) < 0) 
        exit(1); 
  
    /* continued */
    if ((pid = fork()) > 0) { 
        close(p[0]);
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        close(p[1]);
        wait(NULL);
    } 
    else {
        close(p[1]);
        while((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
            printf("%s\n", inbuf); 
        _exit(0);
    } 

    printf("%s\n", inbuf); /* isto é no processo pai por isso o array está vazio */
    return 0; 
}