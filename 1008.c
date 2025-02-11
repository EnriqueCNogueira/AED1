#include <stdio.h>
 
int main() {
    int n, horas;
    float sal;
    
    scanf("%d %d %f", &n, &horas, &sal);
    
    float r = horas * sal;
    
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2f\n", r);
    
    return 0;
}
