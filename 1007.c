#include <stdio.h>
 
int main() {
    int w, x, y, z;
    
    scanf("%d %d %d %d", &w, &x, &y, &z);
    
    int p1 = w * x;
    int p2 = y * z;
    int r = p1 - p2;
    
    printf("DIFERENCA = %d\n", r);
 
    return 0;
}
