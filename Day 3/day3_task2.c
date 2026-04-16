#include <stdio.h>

int main()
{
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues = 0;

    printf("Day 3 - Task 2\n");
    printf("Vendos vleren fillestare: ");
    scanf("%d", &start);

    printf("Vendos vleren perfundimtare: ");
    scanf("%d", &end);

    
    if (start > end)
    {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    
    for (int i = start; i <= end; i++)
    {
        totalValues++;

        if (i % 2 == 0)
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

 
    printf("\n--- Rezultatet ---\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Totali i vlerave: %d\n", totalValues);
    printf("Numrat cift: %d\n", evenCount);
    printf("Numrat tek: %d\n", oddCount);
    printf("Shuma e numrave çift: %d\n", evenSum);
    printf("Shuma e numrave tek: %d\n", oddSum);

    if (evenCount > oddCount)
    {
        printf("Ka me shume numra çift.\n");
    }
    else if (oddCount > evenCount)
    {
        printf("Ka me shume numra tek.\n");
    }
    else
    {
        printf("Ka numer te barabarte te numrave çift dhe tek.\n");
    }

    return 0;
}
