#include <stdio.h>

int main() {
    // deklarimi i variablave
    int age;
    char initial;
    float height;
    double average;
    short year = 2026;
    long population = 8000000;

    // marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial); // hapësira para %c është e rëndësishme

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &height);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &average);

    // output
    printf("\n--- PROFILI I PERDORUESIT ---\n");

    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %f\n", height);
    printf("Mesatarja: %f\n", average);

    printf("Viti (short): %hd\n", year);
    printf("Popullsia (long): %ld\n", population);

    return 0;
}