#include <stdio.h>

int main() {
    int fillimi, fundi;
    int i;

    int countPjestohetMe3 = 0;
    int countPjestohetMe5Jo3 = 0;

    int shumaPjestohetMe3 = 0;
    int shumaPjestohetMe5Jo3 = 0;

    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &fillimi);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &fundi);

    // Kontrolli i input-it
    if (fillimi > fundi) {
        printf("\nInterval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

    // Kalimi neper interval
    for (i = fillimi; i <= fundi; i++) {
        if (i % 3 == 0) {
            countPjestohetMe3++;
            shumaPjestohetMe3 += i;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            countPjestohetMe5Jo3++;
            shumaPjestohetMe5Jo3 += i;
        }
    }

    // Rezultatet
    printf("\n----- REZULTATET -----\n");
    printf("Intervali: [%d, %d]\n", fillimi, fundi);

    printf("\nKategoria 1: Numrat qe pjesetohen me 3\n");
    printf("Numeruesi: %d\n", countPjestohetMe3);
    printf("Shuma: %d\n", shumaPjestohetMe3);

    printf("\nKategoria 2: Numrat qe pjesetohen me 5 por jo me 3\n");
    printf("Numeruesi: %d\n", countPjestohetMe5Jo3);
    printf("Shuma: %d\n", shumaPjestohetMe5Jo3);

    // Krahasimi i shumave
    printf("\n----- KRAHASIMI I SHUMAVE -----\n");
    if (shumaPjestohetMe3 > shumaPjestohetMe5Jo3) {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    }
    else if (shumaPjestohetMe5Jo3 > shumaPjestohetMe3) {
        printf("Shuma e numrave qe pjesetohen me 5 por jo me 3 eshte me e madhe.\n");
    }
    else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}