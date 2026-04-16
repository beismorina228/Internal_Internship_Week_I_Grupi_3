#include <stdio.h>

int main() {

    int nota;

    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &nota);

    if (nota < 0 || nota > 100) {
        printf("Input i pavlefshem!\n");
    }
    else if (nota >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (nota >= 75) {
        printf("Shume mire\n");
    }
    else if (nota >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
