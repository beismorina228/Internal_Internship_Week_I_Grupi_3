#include <stdio.h>

int main() {
    int a;
    double b;

    // Input
    printf("Enter integer value: ");
    scanf("%d", &a);

    printf("Enter double value: ");
    scanf("%lf", &b);

    // Pointers
    int *pA = &a;
    double *pB = &b;

    // Display values
    printf("\n--- BEFORE CHANGE ---\n");
    printf("a = %d\n", a);
    printf("Address of a = %p\n", &a);
    printf("Value using pointer *pA = %d\n", *pA);

    printf("\nb = %.2lf\n", b);
    printf("Address of b = %p\n", &b);
    printf("Value using pointer *pB = %.2lf\n", *pB);

    // Change value using pointer
    int oldA = a;
    *pA = *pA + 10;

    printf("\n--- AFTER CHANGE ---\n");
    printf("Old value of a = %d\n", oldA);
    printf("New value of a = %d\n", a);

    // Condition
    if (a > oldA) {
        printf("Value increased\n");
    }
    else if (a < oldA) {
        printf("Value decreased\n");
    }
    else {
        printf("Value stayed the same\n");
    }

    return 0;
}
