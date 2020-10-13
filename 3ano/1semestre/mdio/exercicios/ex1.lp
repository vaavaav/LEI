/* Variáveis de Decisão

x1: Número de chapéus do tipo 1 produzidos (por dia)
x2: Número de chapéus do tipo 2 produzidos (por dia)

*/

/*Função objetivo*/

max: 5 x1 + 8 x2;

/* Restrições */

0 <= x1; x1 <= 150;
0 <= x2; x2 <= 250;
2 x1  +  x2 <= 500;


int x1;
int x2;