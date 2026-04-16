#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pikeParaprake;
    int opsioniPunetorise;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pikeParaprake);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioniPunetorise);

    printf("\n===== PERMBLEDHJA E REGJISTRIMIT =====\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket paraprake: %.2lf\n", pikeParaprake);

    if (mosha >= 15 && mosha <= 25) {
        printf("Pjesemarrja sipas moshes: Lejohet\n");
    } else {
        printf("Pjesemarrja sipas moshes: Nuk lejohet\n");
    }

    if (pikeParaprake < 50) {
        printf("Klasifikimi: Nevojitet me shume ushtrim\n");
    } else if (pikeParaprake <= 80) {
        printf("Klasifikimi: Gati per vazhdim\n");
    } else {
        printf("Klasifikimi: Gati per sfide\n");
    }

    switch (opsioniPunetorise) {
        case 1:
            printf("Punetoria e zgjedhur: Programim bazik\n");
            break;
        case 2:
            printf("Punetoria e zgjedhur: Web development\n");
            break;
        case 3:
            printf("Punetoria e zgjedhur: Database basics\n");
            break;
        default:
            printf("Punetoria e zgjedhur: Opsion i pavlefshem\n");
            break;
    }

    return 0;
}
