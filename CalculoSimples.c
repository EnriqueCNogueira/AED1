#include <stdio.h>

int main()
{
    int x, n;
    float p, v = 0.0;
    
    scanf("%d %d %f", &x, &n, &p);
    
    v += n*p;
    
    scanf("%d %d %f", &x, &n, &p);
    
    v += n*p;
    
    printf("VALOR A PAGAR: R$ %.2f\n", v);

    return 0;
}
