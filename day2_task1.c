#include <stdio.h>

int main() {

    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short numriIVogel = 25;
    long numriIMadh = 123456;

    // Marrja e input-it
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Shfaqja e profilit
    printf("\n--- PROFILI I PERDORUESIT ---\n");

    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Numri i vogel (short): %d\n", numriIVogel);
    printf("Numri i madh (long): %ld\n", numriIMadh);

    return 0;
}