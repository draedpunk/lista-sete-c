//Area of the Circle
#include <stdio.h>

void achar_area(double *raior, double *resultado_area, double *pi){
    *resultado_area = ((*raior) * (*raior)) * (*pi);
}
 
int main() {
    double r, area, p;
    p = 3.14159;
    double *ptrP = &p;

    scanf("%lf", &r);

    achar_area(&r, &area, ptrP);
    printf("A=%.4lf\n", area);
 
    return 0;
}
