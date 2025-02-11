#include <stdio.h>

int main()
{
    int km;
    float g, c;
    
    scanf("%d %f", &km, &g);
    
    c = km / g;
    
    printf("%.3f km/l\n", c);
    
    return 0;
}
