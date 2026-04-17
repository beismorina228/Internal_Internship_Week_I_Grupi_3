#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;

    short smallNumber = 10;
    long bigNumber = 100000;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average: %.2lf\n", average);
    printf("Short Number: %d\n", smallNumber);
    printf("Long Number: %ld\n", bigNumber);

    return 0;
}
