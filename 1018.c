#include <stdio.h>
#include <math.h>

int main()
{
    int v, val, cem, cinq, vint, dez, cinc, dois, um;
    
    scanf("%d", &val);
    v = val;
    
    cem = v/100;
    v %= 100;
    
    cinq = v/50;
    v %= 50;
    
    vint = v/ 20;
    v %= 20 ;
    
    dez = v/10;
    v %= 10;
    
    cinc = v/5;
    v %= 5;
    
    dois = v/2;
    um = v % 2;
    
    printf("%d\n", val);
    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinq);
    printf("%d nota(s) de R$ 20,00\n", vint);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinc);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", um);
    
    return 0;
}
