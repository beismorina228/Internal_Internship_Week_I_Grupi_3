#include <stdio.h>

int main() {
    int n, choice;

    printf("Enter size (1-12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Invalid input");
        return 0;
    }

    printf("Choose pattern (1 = stars, 2 = numbers): ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice");
    }

    return 0;
}