#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, dx, dy, d;
    
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    
    dx = (x2 - x1)*(x2 - x1);
    dy = (y2 - y1)*(y2 - y1);
    d = sqrt(dx+dy);
    
    printf("%.4f\n", d);
    
    return 0;
}
