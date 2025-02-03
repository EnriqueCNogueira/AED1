#include <stdio.h>
#include <math.h>

int main()
{
    int t, v;
    float l;
    
    scanf("%d %d", &t, &v);
    
    l = ((float)t * (float)v) / 12;
    
    printf("%.3f\n", l);
    
    return 0;
}
