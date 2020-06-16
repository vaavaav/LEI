
#include <stdio.h>
#include <math.h>
int main()
{
    // input
    // calculo com erros sintáticos
    // erros semânticos
    // print
    // calcular as raizes do polinomio ax^2 + bx + c = 0
    float a, b, c, x1 ,x2, s, area;
    //
    printf("Introduza os valores dos termos a,b e c do polinomio ax^2 + bx + c\n");
    scanf("%f %f %f",&a,&b,&c);
    x1 = (-1.0 * b + sqrt(pow(b,2) - 4.0 * a * c)) /(2.0 * a);
    x2 = (-1.0 * b - sqrt(pow(b,2) - 4.0 * a * c)) /(2.0 * a);
    printf("Raizes\nx1 = %f \nx2 = %f \n",x1,x2);

    printf("Introduza os lados do triangulo\n");
    scanf("%f %f %f",&a,&b,&c);
    if(abs(b-c) < a && a < b+c)
    {
        if(a == b && a == c)
            printf("Triangulo Equilatero\n");
        else{
            if (a == b || a == c || b == c)
                printf("Triangulo Isosceles\n");
            else
                printf("Triangulo Escaleno\n");
        }
        s = (a+b+c)/2 ;
        area = sqrt(s * (s-a) * (s-b) * (s-c));
        printf("Area do traingulo: %f", area);
    }
    else
        printf("Triangulo invalido\n");
    return 0;
}

