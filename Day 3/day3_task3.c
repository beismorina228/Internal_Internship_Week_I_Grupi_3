#include <stdio.h>

int main()
{
    int start, end;
    int sumDiv3 = 0, countDiv3 = 0;
    int sumDiv5 = 0, countDiv5 = 0;

    printf("Day 3 - Task 3 \n");

    printf("Vendos fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Vendos fundin e intervalit: ");
    scanf("%d", &end);

    
    if (start > end)
    {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

   
    for (int i = start; i <= end; i++)
    {
        if (i % 3 == 0)
        {
            sumDiv3 += i;
            countDiv3++;
        }
        else if (i % 5 == 0)
        {
            sumDiv5 += i;
            countDiv5++;
        }
    }

    
    printf("\n--- Rezultatet ---\n");
    printf("Intervali: %d deri %d\n", start, end);

    printf("Numrat qe pjesetohen me 3: %d\n", countDiv3);
    printf("Shuma e tyre: %d\n", sumDiv3);

    printf("Numrat qe pjesetohen me 5 por jo me 3: %d\n", countDiv5);
    printf("Shuma e tyre: %d\n", sumDiv5);

   
    if (sumDiv3 > sumDiv5)
    {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    }
    else if (sumDiv5 > sumDiv3)
    {
        printf("Shuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    }
    else
    {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}