#include <stdio.h>

int main() {
    int score;

    printf("Shkruaj rezultatin (0 - 100): ");

    // Kontrollon nëse përdoruesi dha input apo jo
    if (scanf("%d", &score) != 1) {
        printf("Nuk u dha asnje input! Vendos nje numer.\n");
        return 0;
    }

    // Kontrolli i intervalit
    if (score < 0 || score > 100) {
        printf("Input i pavlefshem! Ju lutem vendosni nje numer nga 0 deri ne 100.\n");
    }
    else if (score >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (score >= 50) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}