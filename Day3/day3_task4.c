#include <stdio.h>

int main() {
    int x, originalX;
    double y, originalY;

    int *px;
    double *py;

    printf("Jep nje numer te plote (x): ");
    scanf("%d", &x);

    printf("Jep nje numer decimal (y): ");
    scanf("%lf", &y);

    originalX = x;
    originalY = y;

    px = &x;
    py = &y;

    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("x = %d | Adresa: %p | Pointer: %d\n", x, (void*)px, *px);
    printf("y = %.2lf | Adresa: %p | Pointer: %.2lf\n", y, (void*)py, *py);

    // ndryshim me pointer
    *px = *px + 10;
    *py = *py + 5.5;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("x = %d\n", x);
    printf("y = %.2lf\n", y);

    printf("\n--- ANALIZA ---\n");

    if (x > originalX) {
        printf("x eshte rritur\n");
    } else if (x < originalX) {
        printf("x eshte zvogeluar\n");
    } else {
        printf("x nuk ka ndryshuar\n");
    }

    if (y > originalY) {
        printf("y eshte rritur\n");
    } else if (y < originalY) {
        printf("y eshte zvogeluar\n");
    } else {
        printf("y nuk ka ndryshuar\n");
    }

    if (y >= 0 && y <= 100) {
        printf("y eshte ne intervalin 0 - 100\n");
    } else {
        printf("y eshte jashte intervalit 0 - 100\n");
    }

    return 0;
}