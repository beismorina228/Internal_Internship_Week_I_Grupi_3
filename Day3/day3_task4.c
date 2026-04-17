#include <stdio.h>

int main() {
    int x, originalX;
    double y, originalY;

    int *px;
    double *py;

    // INPUT
    printf("Jep nje numer te plote (x): ");
    scanf("%d", &x);

    printf("Jep nje numer decimal (y): ");
    scanf("%lf", &y);

    // ruaj vlerat fillestare
    originalX = x;
    originalY = y;

    // pointer-at
    px = &x;
    py = &y;

    // PARA NDRYSHIMIT
    printf("\n--- PARA NDRYSHIMIT ---\n");

    printf("Vlera direkte e x: %d\n", x);
    printf("Adresa e x: %p\n", (void*)px);
    printf("Vlera e x permes pointer: %d\n", *px);

    printf("\nVlera direkte e y: %.2lf\n", y);
    printf("Adresa e y: %p\n", (void*)py);
    printf("Vlera e y permes pointer: %.2lf\n", *py);

    // NDRYSHIM ME POINTER
    *px = *px + 10;
    *py = *py + 5.5;

    // PAS NDRYSHIMIT
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("x: nga %d ne %d\n", originalX, x);
    printf("y: nga %.2lf ne %.2lf\n", originalY, y);

    // ANALIZA
    printf("\n--- ANALIZA ---\n");

    if (x > originalX)
        printf("x eshte rritur\n");
    else if (x < originalX)
        printf("x eshte zvogeluar\n");
    else
        printf("x nuk ka ndryshuar\n");

    if (y > originalY)
        printf("y eshte rritur\n");
    else if (y < originalY)
        printf("y eshte zvogeluar\n");
    else
        printf("y nuk ka ndryshuar\n");

    if (y >= 0 && y <= 100)
        printf("y eshte ne intervalin [0,100]\n");
    else
        printf("y eshte jashte intervalit [0,100]\n");

    return 0;
}