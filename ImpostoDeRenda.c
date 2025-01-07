//O código recebe um salário e retorna o imposto de renda inventado

#include <stdio.h>

int main()
{
    float x, i;

    scanf("%f", &x);
    
    if (x <= 2000.0){
        printf("Isento\n");
        return 0;
    }
    else if (x > 2000.0 && x <= 3000.0){
        i = (x - 2000.0) * 0.08;
    }
    else if (x > 3000.0 && x <= 4500.0){
        i = (x - 3000.0) * 0.18 + 80;
    }
    else if (x > 4500.0){
        i = (x - 4500.0) * 0.28 + 350;
    }
    
    printf("R$ %.2f\n", i);

    return 0;
}
