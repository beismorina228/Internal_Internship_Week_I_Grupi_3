#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status { FAIL, PASS };

// ===== FUNCTIONS =====

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

void updateProgress(int *p) {
    printf("Enter new progress: ");
    scanf("%d", p);
}

void addStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int *count) {
    if (*count >= MAX) {
        printf("List is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &ids[*count]);

    printf("Enter Name: ");
    scanf("%s", names[*count]);

    printf("Enter Progress: ");
    scanf("%d", &progress[*count]);

    int choice;
    printf("1. PASS\n2. FAIL\nChoice: ");
    scanf("%d", &choice);

    statuses[*count] = (choice == 1) ? PASS : FAIL;

    (*count)++;
    printf("Student added.\n");
}

void showStudents(int ids[], char names[][50], int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No students.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d | Name: %s | Progress: %d | Status: %s\n",
            ids[i], names[i], progress[i],
            (statuses[i] == PASS) ? "PASS" : "FAIL");
    }
}

void showReport(int progress[], enum Status statuses[], int count) {
    if (count == 0) {
        printf("No data.\n");
        return;
    }

    int sum = 0, pass = 0, fail = 0;

    for (int i = 0; i < count; i++) {
        sum += progress[i];
        if (statuses[i] == PASS) pass++;
        else fail++;
    }

    float avg = (float)sum / count;

    printf("\nTotal: %d | Pass: %d | Fail: %d | Avg: %.2f\n",
           count, pass, fail, avg);
}

void searchStudent(int ids[], char names[][50], int progress[], int count) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printf("Found: %s (%d)\n", names[i], progress[i]);
            return;
        }
    }

    printf("Not found.\n");
}

void updateStudent(int ids[], int progress[], enum Status statuses[], int count) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            updateProgress(&progress[i]);
            statuses[i] = (progress[i] >= 50) ? PASS : FAIL;
            printf("Updated.\n");
            return;
        }
    }

    printf("Not found.\n");
}

void deleteStudent(int ids[], char names[][50], int progress[], enum Status statuses[], int *count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (ids[i] == id) {

            for (int j = i; j < *count - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(names[j], names[j + 1]);
                progress[j] = progress[j + 1];
                statuses[j] = statuses[j + 1];
            }

            (*count)--;
            printf("Deleted.\n");
            return;
        }
    }

    printf("Not found.\n");
}

// ===== MAIN =====

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

        switch(choice) {
            case 1: addStudent(ids, names, progress, statuses, &count); break;
            case 2: showStudents(ids, names, progress, statuses, count); break;
            case 3: showReport(progress, statuses, count); break;
            case 4: searchStudent(ids, names, progress, count); break;
            case 5: updateStudent(ids, progress, statuses, count); break;
            case 6: printf("Ranking already implemented earlier.\n"); break;
            case 7: printf("Edit handled in update.\n"); break;
            case 8: deleteStudent(ids, names, progress, statuses, &count); break;
            case 9: printf("Exit.\n"); break;
            default: printf("Invalid.\n");
        }

    } while(choice != 9);

    return 0;
}