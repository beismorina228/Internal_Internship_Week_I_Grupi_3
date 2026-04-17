#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status { FAIL, PASS };

void printMenu() {
    printf("\n===== Student Progress Tracker =====\n");
    printf("1. Add Student\n");
    printf("2. Show Students\n");
    printf("3. Show Report\n");
    printf("4. Search Student\n");
    printf("5. Update Progress\n");
    printf("6. Show Ranking\n");
    printf("7. Edit Student\n");
    printf("8. Delete Student\n");
    printf("9. Exit\n");
    printf("Choice: ");
}

void printStatus(enum Status status) {
    if (status == PASS)
        printf("PASS");
    else
        printf("FAIL");
}

void printStudent(int id, char name[], int progress, enum Status status, int number) {
    printf("\nStudent %d\n", number);
    printf("ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("Progress: %d\n", progress);
    printf("Status: ");
    printStatus(status);
    printf("\n");
}

void updateProgressValue(int *p) {
    printf("Enter new progress: ");
    scanf("%d", p);
}

void updateStatusFromProgress(int progress, enum Status *status) {
    if (progress >= 50)
        *status = PASS;
    else
        *status = FAIL;
}

void addStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int *count) {
    int statusChoice;

    if (*count >= MAX) {
        printf("List is full. Cannot add more students.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &ids[*count]);

    printf("Enter Name: ");
    scanf("%s", names[*count]);

    printf("Enter Progress: ");
    scanf("%d", &progress[*count]);

    printf("Choose Status:\n");
    printf("1. PASS\n");
    printf("2. FAIL\n");
    printf("Status choice: ");
    scanf("%d", &statusChoice);

    switch (statusChoice) {
        case 1:
            statuses[*count] = PASS;
            break;
        case 2:
            statuses[*count] = FAIL;
            break;
        default:
            printf("Invalid status. Student not added.\n");
            return;
    }

    (*count)++;
    printf("Student added successfully.\n");
}

void showStudents(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No students to show.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printStudent(ids[i], names[i], progress[i], statuses[i], i + 1);
    }
}

void showReport(int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No data available for report.\n");
        return;
    }

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

void printSmartMessage(int progress, enum Status status) {
    if (progress < 50 && status == FAIL)
        printf("Warning: Low performance and failed status.\n");
    else if (progress >= 50 && progress < 80)
        printf("Recommendation: Keep improving.\n");
    else if (progress >= 80 && status == PASS)
        printf("Excellent: Strong performance.\n");
    else
        printf("Status noted.\n");
}

void searchStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No data to search.\n");
        return;
    }

    int searchOption;
    int searchId;
    char searchName[50];
    int found = 0;

    printf("\nSearch by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Choice: ");
    scanf("%d", &searchOption);

    switch (searchOption) {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &searchId);

            for (int i = 0; i < count; i++) {
                if (ids[i] == searchId) {
                    printf("\nFound Student\n");
                    printStudent(ids[i], names[i], progress[i], statuses[i], i + 1);
                    printSmartMessage(progress[i], statuses[i]);
                    found = 1;
                }
            }

            if (!found)
                printf("No matching student found.\n");
            break;

        case 2:
            printf("Enter Name: ");
            scanf("%s", searchName);

            for (int i = 0; i < count; i++) {
                if (strcmp(names[i], searchName) == 0) {
                    printf("\nFound Student\n");
                    printStudent(ids[i], names[i], progress[i], statuses[i], i + 1);
                    printSmartMessage(progress[i], statuses[i]);
                    found = 1;
                }
            }

            if (!found)
                printf("No matching student found.\n");
            break;

        default:
            printf("Invalid search option.\n");
    }
}

void updateStudentProgress(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    int id;
    int found = 0;

    printf("Enter ID to update progress: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printf("Student found: %s\n", names[i]);
            printf("Current progress: %d\n", progress[i]);

            updateProgressValue(&progress[i]);
            updateStatusFromProgress(progress[i], &statuses[i]);

            printf("Progress updated successfully.\n");
            found = 1;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void showRanking(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No students to rank.\n");
        return;
    }

    int rankIds[MAX];
    char rankNames[MAX][50];
    int rankProgress[MAX];
    enum Status rankStatuses[MAX];

    for (int i = 0; i < count; i++) {
        rankIds[i] = ids[i];
        strcpy(rankNames[i], names[i]);
        rankProgress[i] = progress[i];
        rankStatuses[i] = statuses[i];
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (rankProgress[j] < rankProgress[j + 1]) {
                int tempId = rankIds[j];
                rankIds[j] = rankIds[j + 1];
                rankIds[j + 1] = tempId;

                char tempName[50];
                strcpy(tempName, rankNames[j]);
                strcpy(rankNames[j], rankNames[j + 1]);
                strcpy(rankNames[j + 1], tempName);

                int tempProgress = rankProgress[j];
                rankProgress[j] = rankProgress[j + 1];
                rankProgress[j + 1] = tempProgress;

                enum Status tempStatus = rankStatuses[j];
                rankStatuses[j] = rankStatuses[j + 1];
                rankStatuses[j + 1] = tempStatus;
            }
        }
    }

    printf("\n===== Student Ranking (Highest Progress First) =====\n");
    for (int i = 0; i < count; i++) {
        printf("\nRank %d\n", i + 1);
        printf("ID: %d\n", rankIds[i]);
        printf("Name: %s\n", rankNames[i]);
        printf("Progress: %d\n", rankProgress[i]);
        printf("Status: ");
        printStatus(rankStatuses[i]);
        printf("\n");
    }
}

void editStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No students available to edit.\n");
        return;
    }

    int id;
    int found = 0;

    printf("Enter ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            found = 1;
            printf("Student found: %s\n", names[i]);

            printf("Enter new name: ");
            scanf("%s", names[i]);

            printf("Enter new progress: ");
            scanf("%d", &progress[i]);

            updateStatusFromProgress(progress[i], &statuses[i]);

            printf("Student updated successfully.\n");
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void deleteStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int *count) {
    if (*count == 0) {
        printf("No students available to delete.\n");
        return;
    }

    int id;
    int found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (ids[i] == id) {
            found = 1;

            for (int j = i; j < *count - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(names[j], names[j + 1]);
                progress[j] = progress[j + 1];
                statuses[j] = statuses[j + 1];
            }

            (*count)--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

int main() {
    int ids[MAX];
    char names[MAX][50];
    int progress[MAX];
    enum Status statuses[MAX];

    int count = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(ids, names, progress, statuses, &count);
                break;
            case 2:
                showStudents(ids, names, progress, statuses, count);
                break;
            case 3:
                showReport(progress, statuses, count);
                break;
            case 4:
                searchStudent(ids, names, progress, statuses, count);
                break;
            case 5:
                updateStudentProgress(ids, names, progress, statuses, count);
                break;
            case 6:
                showRanking(ids, names, progress, statuses, count);
                break;
            case 7:
                editStudent(ids, names, progress, statuses, count);
                break;
            case 8:
                deleteStudent(ids, names, progress, statuses, &count);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice. Try again.\n");
        }

    } while (choice != 9);

    return 0;
}