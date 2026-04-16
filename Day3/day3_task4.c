#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    printf("Enter integer: ");
    scanf("%d", &a);

    printf("Enter double: ");
    scanf("%lf", &b);

    pA = &a;
    pB = &b;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);
    printf("Value using pointer: %d\n", *pA);

    printf("Value of b: %.2lf\n", b);
    printf("Address of b: %p\n", &b);
    printf("Value using pointer: %.2lf\n", *pB);

    int oldA = a;
    double oldB = b;

    *pA = *pA + 5;
    *pB = *pB * 2;

    printf("New value of a: %d\n", a);
    printf("New value of b: %.2lf\n", b);

    if (a > oldA) {
        printf("a increased\n");
    } else if (a < oldA) {
        printf("a decreased\n");
    } else {
        printf("a unchanged\n");
    }

    if (b > oldB) {
        printf("b increased\n");
    } else if (b < oldB) {
        printf("b decreased\n");
    } else {
        printf("b unchanged\n");
    }

    return 0;
}