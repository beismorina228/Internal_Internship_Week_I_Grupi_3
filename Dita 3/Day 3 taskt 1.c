#include <stdio.h>

// Enum për nivelin e nxënësit
enum Niveli {
    FILLESTAR = 1,
    MESATAR = 2,
    AVANCUAR = 3
};

int main() {
    int i;
    int numri;
    int shuma = 0;
    int numraCift = 0;
    int numraTek = 0;

    // Pjesa 1 - Input
    printf("Shkruaj nje numer pozitiv: ");
    scanf("%d", &numri);

    // Kontroll i thjeshte i input-it
    if (numri <= 0) {
        printf("Duhet te shkruani nje numer me te madh se 0.\n");
        return 1;
    }

    // Pjesa 2 - For loop me kushte
    printf("\nNumrat nga 1 deri ne %d jane:\n", numri);

    for (i = 1; i <= numri; i++) {
        printf("%d ", i);

        shuma += i;

        if (i % 2 == 0) {
            numraCift++;
        } else {
            numraTek++;
        }
    }

    // Pjesa 3 - Rezultatet
    printf("\n\nShuma e numrave nga 1 deri ne %d eshte: %d\n", numri, shuma);
    printf("Numra cift: %d\n", numraCift);
    printf("Numra tek: %d\n", numraTek);

    // Pjesa 4 - Pointer
    int *ptr;
    ptr = &shuma;

    printf("\n--- Pjesa me Pointer ---\n");
    printf("Vlera e shuma: %d\n", shuma);
    printf("Adresa e shuma me &: %p\n", &shuma);
    printf("Adresa e ruajtur ne pointer ptr: %p\n", ptr);
    printf("Vlera e lexuar me *ptr: %d\n", *ptr);

    // Pjesa 5 - Enum
    enum Niveli niveli;

    if (shuma <= 20) {
        niveli = FILLESTAR;
    } else if (shuma <= 50) {
        niveli = MESATAR;
    } else {
        niveli = AVANCUAR;
    }

    printf("\n--- Pjesa me Enum ---\n");

    switch (niveli) {
        case FILLESTAR:
            printf("Niveli i nxenesit: Fillestar\n");
            break;
        case MESATAR:
            printf("Niveli i nxenesit: Mesatar\n");
            break;
        case AVANCUAR:
            printf("Niveli i nxenesit: Avancuar\n");
            break;
        default:
            printf("Niveli nuk u percaktua.\n");
    }

    return 0;
}