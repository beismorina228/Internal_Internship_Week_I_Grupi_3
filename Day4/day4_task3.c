#include <stdio.h>

#define MAX 5

enum Status { FAIL, PASS };

int main() {
    int ids[MAX];
    char names[MAX][50];
    int progress[MAX];
    enum Status statuses[MAX];

    int count = 0;
    int choice;
    int statusChoice;

    do {
        printf("\n1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

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

                    printf("Choose Status:\n");
                    printf("1. PASS\n");
                    printf("2. FAIL\n");
                    printf("Status choice: ");
                    scanf("%d", &statusChoice);

                    switch (statusChoice) {
                        case 1:
                            statuses[count] = PASS;
                            break;
                        case 2:
                            statuses[count] = FAIL;
                            break;
                        default:
                            printf("Invalid status. Student not added.\n");
                            continue;
                    }

                    count++;
                    printf("Student added successfully.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No students to show.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("\nStudent %d\n", i + 1);
                        printf("ID: %d\n", ids[i]);
                        printf("Name: %s\n", names[i]);
                        printf("Progress: %d\n", progress[i]);

                        if (statuses[i] == PASS)
                            printf("Status: PASS\n");
                        else
                            printf("Status: FAIL\n");
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo data available for report.\n");
                } else {
                    int passCount = 0;
                    int failCount = 0;
                    int sum = 0;
                    int highest = progress[0];
                    int lowest = progress[0];
                    float average;

                    for (int i = 0; i < count; i++) {
                        sum += progress[i];

                        if (statuses[i] == PASS)
                            passCount++;
                        else
                            failCount++;

                        if (progress[i] > highest)
                            highest = progress[i];

                        if (progress[i] < lowest)
                            lowest = progress[i];
                    }

                    average = (float)sum / count;

                    printf("\n===== Student Report =====\n");
                    printf("Total students: %d\n", count);
                    printf("Passed: %d\n", passCount);
                    printf("Failed: %d\n", failCount);
                    printf("Average progress: %.2f\n", average);
                    printf("Highest progress: %d\n", highest);
                    printf("Lowest progress: %d\n", lowest);

                    if (average >= 80)
                        printf("Class performance: Excellent\n");
                    else if (average >= 50)
                        printf("Class performance: Good\n");
                    else
                        printf("Class performance: Needs Improvement\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}