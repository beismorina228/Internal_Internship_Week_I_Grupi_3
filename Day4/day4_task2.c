#include <stdio.h>

#define MAX 5

// ENUM (Task 2 requirement)
enum Status { FAIL, PASS };

int main() {

    int ids[MAX];
    char names[MAX][50];
    int progress[MAX];
    enum Status statuses[MAX]; // store status for each student

    int count = 0;
    int choice;
    int statusChoice;

    do {
        printf("\n1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            // ADD STUDENT
            case 1:
                if (count >= MAX) {
                    printf("List is full. Cannot add more students.\n");
                } else {
                    printf("Enter ID: ");
                    scanf("%d", &ids[count]);

                    printf("Enter Name: ");
                    scanf("%s", names[count]);

                    printf("Enter Progress: ");
                    scanf("%d", &progress[count]);

                    // NEW PART (Task 2)
                    printf("Choose Status:\n");
                    printf("1. PASS\n");
                    printf("2. FAIL\n");
                    printf("Status choice: ");
                    scanf("%d", &statusChoice);

                    // SECOND SWITCH (Task 2 requirement)
                    switch(statusChoice) {
                        case 1:
                            statuses[count] = PASS;
                            break;
                        case 2:
                            statuses[count] = FAIL;
                            break;
                        default:
                            printf("Invalid status. Student not added.\n");
                            continue; // skip adding
                    }

                    count++;
                    printf("Student added successfully.\n");
                }
                break;

            // SHOW STUDENTS
            case 2:
                if (count == 0) {
                    printf("No students to show.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("\nStudent %d\n", i + 1);
                        printf("ID: %d\n", ids[i]);
                        printf("Name: %s\n", names[i]);
                        printf("Progress: %d\n", progress[i]);

                        // SHOW STATUS (Task 2 requirement)
                        if (statuses[i] == PASS)
                            printf("Status: PASS\n");
                        else
                            printf("Status: FAIL\n");
                    }
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice. Try again.\n");
        }

    } while(choice != 3);

    return 0;
}