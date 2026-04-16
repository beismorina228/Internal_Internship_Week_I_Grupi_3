#include <stdio.h>

int main() {
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    // Marrim input nga perdoruesi
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Kontrollojme nese intervali eshte valid
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 0;
    }

    // For loop per te kaluar neper interval
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    int totalNumbers = countEven + countOdd;

    // Output
    printf("\n--- REZULTATET ---\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("Numra çift: %d\n", countEven);
    printf("Shuma e numrave çift: %d\n", sumEven);

    printf("Numra tek: %d\n", countOdd);
    printf("Shuma e numrave tek: %d\n", sumOdd);

    // Krahasimi
    if (countEven > countOdd) {
        printf("Ka me shume numra çift.\n");
    } else if (countOdd > countEven) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}