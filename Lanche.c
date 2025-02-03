#include <stdio.h>

int main() {
    int x, n;
    
    scanf("%d %d", &x, &n);
    
    if (x == 1) {
        printf("Total: R$ %.2f\n", 4.0*(float)n);
    } 
    else if (x == 2) {
        printf("Total: R$ %.2f\n", 4.5*(float)n);
    } 
    else if (x == 3) {
        printf("Total: R$ %.2f\n", 5.0*(float)n);
    } 
    else if (x == 4) {
        printf("Total: R$ %.2f\n", 2.0*(float)n);
    } 
    else {
        printf("Total: R$ %.2f\n", 1.5*(float)n);
    } 

    return 0;
}
