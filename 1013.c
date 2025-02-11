#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, maiorAB, maior;
        
    scanf("%d %d %d", &a, &b, &c);
    
    maiorAB = (a + b + abs(a - b)) / 2;
    maior = (maiorAB + c + abs(maiorAB - c)) / 2;
    
    printf("%d eh o maior\n", maior);
    return 0;
}
