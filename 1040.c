#include <stdio.h>

int main() {
    float n1, n2, n3, n4, e, media;
    
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    
    media = ((2*n1) + (3*n2) + (4*n3) + n4) / 10; 
    
    if (media >= 7.0){
        printf("Media: %.1f\n", media);
        printf("Aluno aprovado.\n");
    }
    else if(media < 5.0){
        printf("Media: %.1f\n", media);
        printf("Aluno reprovado.\n");
    }
    else{
        scanf("%f", &e);
        if((media + e)/2 >= 5){
            printf("Media: %.1f\n", media);
            printf("Aluno em exame.\n");
            printf("Nota do exame: %.1f\n", e);
            printf("Aluno aprovado.\n");
        }
        else{
            printf("Media: %.1f\n", media);
            printf("Aluno em exame.\n");
            printf("Nota do exame: %.1f\n", e);
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", (media + e)/2);
    }
        

    return 0;
}
