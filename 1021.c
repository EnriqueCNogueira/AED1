#include <stdio.h>
#include <math.h>

int main()
{
    int cem, cinq, vint, dez, cinc, dois, um, mcinq, mvint, mdez, mcinc, mum;
    double v;

    scanf("%lf", &v);

    int valor = (int)v;
    int moedas = (int)round((v - valor) * 100);

    cem = valor / 100;
    valor %= 100;

    cinq = valor / 50;
    valor %= 50;

    vint = valor / 20;
    valor %= 20;

    dez = valor / 10;
    valor %= 10;

    cinc = valor / 5;
    valor %= 5;

    dois = valor / 2;
    valor %= 2;

    um = valor;

    mcinq = moedas / 50;
    moedas %= 50;

    mvint = moedas / 25;
    moedas %= 25;

    mdez = moedas / 10;
    moedas %= 10;

    mcinc = moedas / 5;
    mum = moedas % 5;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", cem);
    printf("%d nota(s) de R$ 50.00\n", cinq);
    printf("%d nota(s) de R$ 20.00\n", vint);
    printf("%d nota(s) de R$ 10.00\n", dez);
    printf("%d nota(s) de R$ 5.00\n", cinc);
    printf("%d nota(s) de R$ 2.00\n", dois);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", um);
    printf("%d moeda(s) de R$ 0.50\n", mcinq);
    printf("%d moeda(s) de R$ 0.25\n", mvint);
    printf("%d moeda(s) de R$ 0.10\n", mdez);
    printf("%d moeda(s) de R$ 0.05\n", mcinc);
    printf("%d moeda(s) de R$ 0.01\n", mum);

    return 0;
}
