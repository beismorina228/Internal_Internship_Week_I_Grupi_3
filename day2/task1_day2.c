#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vitiShkolles;
    long popullsia;

    // Marrja e input-it
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine (p.sh. 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Vlera shtese (mund edhe si input, por ketu i kemi caktu ne kod)
    vitiShkolles = 11;
    popullsia = 200000;

    // Output i organizuar
    printf("\n--- PROFILI I PERDORUESIT ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Viti i shkolles: %hd\n", vitiShkolles);
    printf("Popullsia e qytetit: %ld\n", popullsia);

    return 0;
}
