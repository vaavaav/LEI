/* Variáveis de Decisão

xij: área usada para produto j {t, a, c} na quinta i {1,2,3}

*/

/*Função objetivo*/

max: 4 x1t + 3 x1a + x1c + 4 x2t + 3 x2a + x2c + 4 x3t + 3 x3a + x3c;

/* Restrições */

// área arável

x1t + x1a + x1c <= 40;
x2t + x2a + x2c <= 60;
x3t + x3a + x3c <= 30;

// consumo de água

3 x1t + 2 x1a + x1c <= 60;
3 x2t + 2 x2a + x2c <= 80;
3 x3t + 2 x3a + x3c <= 37.5;

// área máxima

x1t + x2t + x3t <= 60;
x1a + x2a + x3a <= 50;
x1c + x2c + x3c <= 32.5;

//proporção de área áravel

1.5 x1t + 1.5 x1a + 1.5 x1c = x2t + x2a + x2c;
0.75 x1t + 0.75 x1a + 0.75 x1c = x3t + x3a + x3c; 



