#include <stdio.h>

int main()
{
    int age;
    char initial;
    float height;
    double average;

    short luckyNumber = 7;
    long phoneNumber = 123456789;

    printf("Enter your age:\n");
    scanf("%d", &age);

    printf("Enter your initial:\n");
    scanf(" %c", &initial);

    printf("Enter your height:\n");
    scanf("%f", &height);

    printf("Enter your average:\n");
    scanf("%lf", &average);

    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %f\n", height);
    printf("Average: %f\n", average);
    printf("Lucky Number (short): %d\n", luckyNumber);
    printf("Phone Number (long): %ld\n", phoneNumber);

    return 0;
}