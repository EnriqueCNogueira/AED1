#include <stdio.h>

int main()
{
    double a, b, c, at, ac, atr, aq, ar, pi = 3.14159;
    
    scanf("%lf %lf %lf", &a, &b, &c);
    
    at = (a * c) / 2;
    ac = c * c * pi;
    atr = (a + b) * c/2;
    aq = b * b;
    ar = a * b;
    
    printf("TRIANGULO: %.3lf\n", at);
    printf("CIRCULO: %.3lf\n", ac);
    printf("TRAPEZIO: %.3lf\n", atr);
    printf("QUADRADO: %.3lf\n", aq);
    printf("RETANGULO: %.3lf\n", ar);
    
    return 0;
}
