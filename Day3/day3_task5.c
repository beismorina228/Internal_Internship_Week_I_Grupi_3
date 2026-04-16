#include <stdio.h>

int main() {
    enum Level {BEGINNER = 1, INTERMEDIATE, ADVANCED, EXPERT};

    int choice;
    int validCount = 0;
    int invalidCount = 0;

    for (int i = 1; i <= 3; i++) {
        printf("Enter choice for user %d (1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert): ", i);
        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Invalid choice\n");
            invalidCount++;
            continue;
        }

        validCount++;

        enum Level level = choice;

        switch (level) {
            case BEGINNER:
                printf("Message: Beginner level selected\n");
                break;
            case INTERMEDIATE:
                printf("Message: Intermediate level selected\n");
                break;
            case ADVANCED:
                printf("Message: Advanced level selected\n");
                break;
            case EXPERT:
                printf("Message: Expert level selected\n");
                break;
            default:
                printf("Invalid choice\n");
                invalidCount++;
        }
    }

    printf("\nStatistics:\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}