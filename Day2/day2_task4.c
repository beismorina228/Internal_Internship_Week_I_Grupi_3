#include <stdio.h>

int main()
{
    int age, option;
    char initial;
    double points;

    printf("Enter age:\n");
    scanf("%d", &age);

    printf("Enter initial:\n");
    scanf(" %c", &initial);

    printf("Enter points:\n");
    scanf("%lf", &points);

    printf("Enter workshop option (1-3):\n");
    scanf("%d", &option);

    // AGE CHECK
    if (age < 10 || age > 18) {
        printf("Not eligible for participation\n");
    } else {
        printf("Eligible for participation\n");
    }

    // CLASSIFICATION
    if (points < 50) {
        printf("Needs more practice\n");
    }
    else if (points < 80) {
        printf("Ready to continue\n");
    }
    else {
        printf("Ready for challenge\n");
    }

    // SWITCH (WORKSHOP)
    switch(option) {
        case 1:
            printf("Workshop: Programming\n");
            break;
        case 2:
            printf("Workshop: Robotics\n");
            break;
        case 3:
            printf("Workshop: Design\n");
            break;
        default:
            printf("Invalid workshop\n");
    }

    // SUMMARY
    printf("\n--- Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Points: %f\n", points);
    printf("Option: %d\n", option);

    return 0;
}