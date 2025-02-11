#include <stdio.h>
 
int main() {
    char nome[20];
    double sal, com;
    
    scanf("%s", nome);
    scanf("%lf %lf", &sal, &com);
    
    double r = sal + (com * 0.15);
    
    printf("TOTAL = R$ %.2lf\n", r);
    
    return 0;
}
