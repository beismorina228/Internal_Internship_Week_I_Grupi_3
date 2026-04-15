#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    // INPUT
    printf("Sheno moshen: ");
    scanf("%d", &mosha);

    printf("Sheno inicialin: ");
    scanf(" %c", &iniciali);

    printf("Sheno piket: ");
    scanf("%lf", &piket);

    printf("Zgjedh punetorine (1-3): ");
    scanf("%d", &opsioni);

    printf("\n--- KONTROLLI I MOSHES ---\n");

    // kontroll moshe
    if (mosha >= 15 && mosha <= 25) {
        printf("Mosha eshte brenda kufirit.\n");
    } else {
        printf("Mosha nuk eshte brenda kufirit!\n");
    }

    printf("\n--- KLASIFIKIMI I PIKET ---\n");

    // IF / ELSE për pikët
    if (piket < 50) {
        printf("Nevojitet me shume ushtrim.\n");
    }
    else if (piket < 80) {
        printf("Gati per vazhdim.\n");
    }
    else {
        printf("Gati per sfide.\n");
    }

    printf("\n--- PUNETORIA E ZGJEDHUR ---\n");

    // SWITCH për punëtorinë
    switch (opsioni) {
        case 1:
            printf("Punetoria A\n");
            break;

        case 2:
            printf("Punetoria B\n");
            break;

        case 3:
            printf("Punetoria C\n");
            break;

        default:
            printf("Opsion i pavlefshem!\n");
    }

    printf("\n--- PERMBLEDHJE FINALE ---\n");

    // OUTPUT FINAL
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %lf\n", piket);
    printf("Opsioni i punetorise: %d\n", opsioni);

    return 0;
}