void fill(int *vetor, int size, int value){
	int i;
	for(i = 0; i < size; i++)
		vetor[i] = value;
}

int find(int *vetor, int size, int value){
	int i; 
	for(i = 0; i < size && vetor[i]!= value; i++);
	return(vetor[i] == value ? i : -1);
}
