#include <stdio.h>

int main()
{
    int start, end;
    int i;

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Input nga përdoruesi
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if(start > end)
    {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // For loop për analizë
    for(i = start; i <= end; i++)
    {
        if(i % 2 == 0)
        {
            evenCount++;
            evenSum += i;
        }
        else
        {
            oddCount++;
            oddSum += i;
        }
    }

    // Rezultatet finale
    printf("\n--- REZULTATET ---\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Numri total i vlerave: %d\n", end - start + 1);

    printf("Numra çift: %d\n", evenCount);
    printf("Shuma e numrave çift: %d\n", evenSum);

    printf("Numra tek: %d\n", oddCount);
    printf("Shuma e numrave tek: %d\n", oddSum);

    // Krahasimi
    if(evenCount > oddCount)
    {
        printf("Ka me shume numra çift.\n");
    }
    else if(oddCount > evenCount)
    {
        printf("Ka me shume numra tek.\n");
    }
    else
    {
        printf("Numrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}