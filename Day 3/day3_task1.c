#include <stdio.h>

int main()
{
    int size, choice;

    printf("=== Day 3 - Task 1 ===\n");
    printf("Enter pattern size (1 - 12): ");
    scanf("%d", &size);

    // Input validation
    if (size < 1 || size > 12)
    {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 1;
    }

    printf("\nChoose pattern type:\n");
    printf("1. Star Pattern\n");
    printf("2. Number Pattern\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nStar Pattern:\n");

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if (choice == 2)
    {
        printf("\nNumber Pattern:\n");

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}