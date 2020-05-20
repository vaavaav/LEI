#include <stdlib.h>
#include <stdio.h>
#include "api.h"

int main(){
	int vetor[10];
	fill(vetor,10,0);
	fill(vetor + 5,4,1);
	printf("There is a \"1\" in position number %d",find(vetor,10,1));
}

