#include <stdio.h>

int main()
{
    int size;
    int choice;
    int i, j;

    printf("Shkruaj madhesine e pattern-it (1 deri 12): ");
    scanf("%d", &size);

    if (size < 1 || size > 12)
    {
        printf("Input i pavlefshem. Ju lutem shkruani nje numer nga 1 deri ne 12.\n");
        return 1;
    }

    printf("Zgjedh pattern-in:\n");
    printf("1. Pattern me yje\n");
    printf("2. Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nPattern me yje:\n");
        for (i = 1; i <= size; i++)
        {
            for (j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if (choice == 2)
    {
        printf("\nPattern me numra:\n");
        for (i = 1; i <= size; i++)
        {
            for (j = 1; j <= i; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Zgjedhje e pavlefshme. Duhet te zgjidhni 1 ose 2.\n");
        return 1;
    }

    return 0;
}
