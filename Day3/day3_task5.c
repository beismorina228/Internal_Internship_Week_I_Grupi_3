#include <stdio.h>

// Define enum with 4 values
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0;
    int invalidCount = 0;

    printf("=== Student Level Program ===\n");

    // Loop for 3 test cases/users
    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d:\n", i);
        printf("Choose level:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("4. Expert\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check input using switch
        switch (choice) {
            case BEGINNER:
                printf("You are a Beginner. Start learning basics.\n");
                validCount++;
                break;
            case INTERMEDIATE:
                printf("You are Intermediate. Keep practicing.\n");
                validCount++;
                break;
            case ADVANCED:
                printf("You are Advanced. Work on complex problems.\n");
                validCount++;
                break;
            case EXPERT:
                printf("You are Expert. You master the subject!\n");
                validCount++;
                break;
            default:
                printf("Invalid choice! Please enter a number between 1-4.\n");
                invalidCount++;
        }
    }

    // Final statistics
    printf("\n=== Statistics ===\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}