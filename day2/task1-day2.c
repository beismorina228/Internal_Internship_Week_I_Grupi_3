#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;

    short smallNumber = 10;
    long bigNumber = 100000;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);  

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    // Output
    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average: %.2lf\n", average);
    printf("Short value: %d\n", smallNumber);
    printf("Long value: %ld\n", bigNumber);

    return 0;
}
