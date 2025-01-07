//Este código recebe 6 números não nulos e retorna quantos números positivos foram inseridos

#include <stdio.h>

int main(){
    int n=0;
    float x;
    
    for(int i=0; i<6; i++){
        scanf("%f", &x);
        if (x>0)
            n++;
    }
    
    printf("%d valores positivos\n", n);

    return 0;
}
