#include <stdio.h>
 
int main() {
    double x , y, z;
    
    scanf("%lf %lf %lf", &x, &y, &z);
    
    x = x * 0.2;
    y = y * 0.3;
    z = z * 0.5;
    
    double r = x + y + z;
    
    printf("MEDIA = %.1lf\n", r);
    
    return 0;
}
