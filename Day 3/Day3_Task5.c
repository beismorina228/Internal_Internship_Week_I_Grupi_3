#include <stdio.h>

enum Level
{
    Beginner = 1,
    Intermediate,
    Advanced,
    Expert
};

int main()
{
    int choice;
    int validCount = 0, invalidCount = 0;

    printf(" Day 3 - Task 5 \n");

    for (int i = 1; i <= 3; i++)
    {
        printf("\nPerdoruesi %d\n", i);
        printf("Zgjedh nivelin:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("4. Expert\n");
        printf("Vendos zgjedhjen: ");
        scanf("%d", &choice);

        enum Level studentLevel = choice;

        switch (studentLevel)
        {
            case Beginner:
                printf("Nxenesi eshte ne nivel fillestar.\n");
                validCount++;
                break;

            case Intermediate:
                printf("Nxenesi eshte ne nivel mesatar.\n");
                validCount++;
                break;

            case Advanced:
                printf("Nxenesi eshte ne nivel te avancuar.\n");
                validCount++;
                break;

            case Expert:
                printf("Nxenesi eshte ne nivel ekspert.\n");
                validCount++;
                break;

            default:
                printf("Input i pavlefshem!\n");
                invalidCount++;
                break;
        }
    }

    printf("\n-
         Statistikat -\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}
