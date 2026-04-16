#include <stdio.h>

int main() {
    int fillimi, fundi;
    int i;

    int countCift = 0, countTek = 0;
    int shumaCift = 0, shumaTek = 0;
    int totalVlera = 0;

    printf("Shkruaj vleren fillestare te intervalit: ");
    scanf("%d", &fillimi);

    printf("Shkruaj vleren perfundimtare te intervalit: ");
    scanf("%d", &fundi);

    // Kontrolli i intervalit
    if (fillimi > fundi) {
        printf("\nInterval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    // Analiza e numrave ne interval
    for (i = fillimi; i <= fundi; i++) {
        totalVlera++;

        if (i % 2 == 0) {
            countCift++;
            shumaCift += i;
        } else {
            countTek++;
            shumaTek += i;
        }
    }

    // Rezultatet
    printf("\n----- REZULTATET -----\n");
    printf("Intervali: [%d, %d]\n", fillimi, fundi);
    printf("Totali i vlerave ne interval: %d\n", totalVlera);
    printf("Numra cift: %d\n", countCift);
    printf("Numra tek: %d\n", countTek);
    printf("Shuma e numrave cift: %d\n", shumaCift);
    printf("Shuma e numrave tek: %d\n", shumaTek);

    // Krahasimi i kategorive
    if (countCift > countTek) {
        printf("Kategoria me me shume numra: Numrat cift\n");
    } else if (countTek > countCift) {
        printf("Kategoria me me shume numra: Numrat tek\n");
    } else {
        printf("Te dy kategorite kane numer te barabarte vlerash.\n");
    }

    return 0;
}