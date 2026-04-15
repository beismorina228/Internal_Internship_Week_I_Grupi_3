#include <stdio.h>

int main()
{
    int day;

    printf("Enter a number (1-7):\n");
    scanf("%d", &day);

    switch(day) {

        case 1:
            printf("Monday - Working day\n");
            break;

        case 2:
            printf("Tuesday - Working day\n");
            break;

        case 3:
            printf("Wednesday - Working day\n");
            break;

        case 4:
            printf("Thursday - Working day\n");
            break;

        case 5:
            printf("Friday - Working day\n");
            break;

        case 6:
            printf("Saturday - Weekend\n");
            break;

        case 7:
            printf("Sunday - Weekend\n");
            break;

        default:
            printf("Invalid input\n");
    }

    return 0;
}