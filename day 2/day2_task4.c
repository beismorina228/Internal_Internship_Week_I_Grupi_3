#include <stdio.h>

int main() {
    int mosha, opsioni;
    char iniciali;
    double pike;

  
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj pike paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    
    if (mosha < 15 || mosha > 25) {
        printf("\nNuk je brenda kufirit te lejuar per pjesemarrje (15-25).\n");
    } else {
        printf("\nMosha eshte valide per pjesemarrje.\n");
    }

  
    char* niveli;

    if (pike < 50) {
        niveli = "Nevojitet me shume ushtrim";
    } else if (pike < 80) {
        niveli = "Gati per vazhdim";
    } else {
        niveli = "Gati per sfide";
    }

    
    char* punetoria;

    switch (opsioni) {
        case 1:
            punetoria = "Programim Bazik";
            break;
        case 2:
            punetoria = "Algoritme";
            break;
        case 3:
            punetoria = "Zhvillim Web";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
            break;
    }

 
    printf("\n PERMBLEDHJE \n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2lf\n", pike);
    printf("Niveli: %s\n", niveli);
    printf("Punetoria: %s\n", punetoria);

    return 0;
}
