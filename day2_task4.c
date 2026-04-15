#include <stdio.h>

int main() {

    // Variablat
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    // Input nga përdoruesi
    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruani piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjidhni punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    if (mosha >= 10 && mosha <= 18) {
        printf("Mosha eshte brenda kufirit per pjesemarrje.\n");
    } else {
        printf("Mosha nuk eshte brenda kufirit per pjesemarrje.\n");
    }

    // Klasifikimi sipas pikeve
    printf("\nRezultati i klasifikimit: ");

    if (piket < 50) {
        printf("Nevojitet me shume ushtrim.\n");
    }
    else if (piket >= 50 && piket < 80) {
        printf("Gati per vazhdim.\n");
    }
    else {
        printf("Gati per sfide.\n");
    }

    // Zgjedhja e punetorise me switch
    printf("\nPunetoria e zgjedhur: ");

    switch (opsioni) {
        case 1:
            printf("Programim bazik\n");
            break;

        case 2:
            printf("Robotike\n");
            break;

        case 3:
            printf("Dizajn grafik\n");
            break;

        default:
            printf("Opsion i pavlefshem\n");
    }

    // Permbledhja finale
    printf("\n--- Permbledhje ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2lf\n", piket);
    printf("Opsioni i zgjedhur: %d\n", opsioni);

    return 0;
}