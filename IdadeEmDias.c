//Este código recebe um número n e retorna quantos anos meses e dias correspondem a esse número

#include <stdio.h>
 
int main() {
    int dia, mes, ano, n, resto;
    
    scanf("%d", &n);
    
    ano = n/365;
    resto = n%365;
    
    mes = resto/30;
    dia = resto%30;
 
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
    
    return 0;
}
