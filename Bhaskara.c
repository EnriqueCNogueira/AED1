#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delt, r1, r2;

    scanf("%lf %lf %lf", &a, &b, &c);

    delt = (b * b) - (4 * a * c);

    if (delt < 0 || a == 0.0) {
        printf("Impossivel calcular\n");
    } else {
        delt = sqrt(delt);
        r1 = (-b + delt) / (2 * a);
        r2 = (-b - delt) / (2 * a);
        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }

    return 0;
}
