#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5Not3 = 0, sumDiv5Not3 = 0;

    // Input nga perdoruesi
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Kontroll i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    // Loop neper interval
    for (int i = start; i <= end; i++) {

        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    // Output
    printf("\n--- REZULTATET ---\n");
    printf("Intervali: %d deri %d\n", start, end);

    printf("\nNumra qe pjestohen me 3:\n");
    printf("Numeruesi: %d\n", countDiv3);
    printf("Shuma: %d\n", sumDiv3);

    printf("\nNumra qe pjestohen me 5 (por jo me 3):\n");
    printf("Numeruesi: %d\n", countDiv5Not3);
    printf("Shuma: %d\n", sumDiv5Not3);

    // Krahasimi i shumave
    if (sumDiv3 > sumDiv5Not3) {
        printf("\nShuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } 
    else if (sumDiv5Not3 > sumDiv3) {
        printf("\nShuma e numrave qe pjestohen me 5 (jo me 3) eshte me e madhe.\n");
    } 
    else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}