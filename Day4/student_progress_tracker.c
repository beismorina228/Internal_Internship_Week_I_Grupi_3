#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LEN 50

/* ================= ENUM ================= */
typedef enum {
    STATUS_ACTIVE = 0,
    STATUS_PASSED = 1,
    STATUS_FAILED = 2
} StudentStatus;

/* ================= STRUCT ================= */
typedef struct {
    int id;
    char name[NAME_LEN];
    int score;
    StudentStatus status;
} Student;

/* ================= STATUS ================= */
const char* statusToString(StudentStatus s) {
    switch (s) {
        case STATUS_ACTIVE: return "Active";
        case STATUS_PASSED: return "Passed";
        case STATUS_FAILED: return "Failed";
        default: return "Unknown";
    }
}

/* ================= STATUS INPUT ================= */
int chooseStatus(StudentStatus *outStatus) {
    int choice;

    printf("  Zgjidhni statusin:\n");
    printf("    1. Active\n");
    printf("    2. Passed\n");
    printf("    3. Failed\n");
    printf("  Zgjedhja: ");

    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("  [!] Input i pavlefshem.\n");
        return 0;
    }

    switch (choice) {
        case 1: *outStatus = STATUS_ACTIVE; return 1;
        case 2: *outStatus = STATUS_PASSED; return 1;
        case 3: *outStatus = STATUS_FAILED; return 1;
        default:
            printf("  [!] Zgjedhje e pavlefshme.\n");
            return 0;
    }
}

/* ================= TASK 4 (REAL POINTER USAGE) ================= */
/* This function REALLY modifies data via pointer */
void updateStudentScore(Student *s, int newScore) {
    if (newScore < 0 || newScore > 100) {
        printf("  [!] Score i pavlefshem.\n");
        return;
    }

    s->score = newScore;

    /* automatic status update based on new score */
    if (newScore >= 80)
        s->status = STATUS_PASSED;
    else if (newScore < 50)
        s->status = STATUS_FAILED;
    else
        s->status = STATUS_ACTIVE;

    printf("  [OK] Score u perditesua me sukses!\n");
}

/* ================= ADD STUDENT ================= */
int addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n  [!] Kapaciteti u mbush.\n");
        return 0;
    }

    char name[NAME_LEN];
    int score;
    StudentStatus status;

    printf("\n  Emri: ");
    if (scanf(" %49[^\n]", name) != 1) return 0;

    printf("  Score (0-100): ");
    if (scanf("%d", &score) != 1 || score < 0 || score > 100) {
        printf("  [!] Score i pavlefshem.\n");
        return 0;
    }

    if (!chooseStatus(&status)) return 0;

    students[*count].id = *count + 1;
    strncpy(students[*count].name, name, NAME_LEN);
    students[*count].score = score;
    students[*count].status = status;

    (*count)++;

    printf("  [OK] Student i shtuar!\n");
    return 1;
}

/* ================= PRINT ================= */
void printStudent(const Student *s) {
    printf("  ID:%d | %-10s | %3d | %s\n",
           s->id, s->name, s->score, statusToString(s->status));
}

void printAllStudents(const Student students[], int count) {
    if (count == 0) {
        printf("\n  [!] Nuk ka regjistrime.\n");
        return;
    }

    printf("\n  ===== LISTA =====\n");
    for (int i = 0; i < count; i++) {
        printStudent(&students[i]);
    }
}

/* ================= REPORT ================= */
void printReport(const Student students[], int count) {
    printf("\n  ===== RAPORT =====\n");

    if (count == 0) {
        printf("  No data.\n");
        return;
    }

    int sum = 0, max = students[0].score, min = students[0].score;
    int passed = 0, failed = 0, active = 0;

    for (int i = 0; i < count; i++) {
        int s = students[i].score;
        sum += s;

        if (s > max) max = s;
        if (s < min) min = s;

        if (students[i].status == STATUS_PASSED) passed++;
        else if (students[i].status == STATUS_FAILED) failed++;
        else active++;
    }

    float avg = (float)sum / count;

    printf("  Total: %d\n", count);
    printf("  Passed: %d\n", passed);
    printf("  Failed: %d\n", failed);
    printf("  Active: %d\n", active);
    printf("  Avg: %.2f\n", avg);
    printf("  Max: %d\n", max);
    printf("  Min: %d\n", min);
}

/* ================= TASK 5 (SEARCH + FILTER + WARNINGS) ================= */
void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\n  [!] Nuk ka te dhena.\n");
        return;
    }

    int choice;
    printf("\n  1. Search by ID\n  2. Search by Name\n  Zgjedhja: ");

    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("  [!] Input i pavlefshem.\n");
        return;
    }

    if (choice == 1) {
        int id;
        printf("  ID: ");
        scanf("%d", &id);

        int found = 0;

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                found = 1;

                printf("\n  ===== RESULT =====\n");
                printStudent(&students[i]);

                /* warnings logic */
                if (students[i].score < 50 && students[i].status != STATUS_FAILED)
                    printf("  [!] WARNING: Low score but not failed!\n");
                else if (students[i].score >= 90 && students[i].status == STATUS_ACTIVE)
                    printf("  [!] NOTE: Excellent but still active!\n");
                else
                    printf("  [OK] Data OK.\n");
            }
        }

        if (!found)
            printf("  [!] Nuk u gjet.\n");
    }

    else if (choice == 2) {
        char name[NAME_LEN];
        printf("  Name: ");
        scanf(" %49[^\n]", name);

        int found = 0;

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                found = 1;

                printf("\n  ===== RESULT =====\n");
                printStudent(&students[i]);

                if (students[i].score < 50)
                    printf("  [!] WARNING: Weak performance!\n");
                else if (students[i].score >= 90)
                    printf("  [!] RECOMMENDATION: Excellent student!\n");
                else
                    printf("  [OK]\n");
            }
        }

        if (!found)
            printf("  [!] Nuk u gjet.\n");
    }
}

/* ================= MENU ================= */
void menu(int count) {
    printf("\n===== MENU (%d/%d) =====\n", count, MAX_STUDENTS);
    printf("1. Add student\n");
    printf("2. Show students\n");
    printf("3. Report\n");
    printf("4. Update score (POINTER TASK)\n");
    printf("5. Search\n");
    printf("6. Exit\n");
    printf("Choice: ");
}

/* ================= MAIN ================= */
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        menu(count);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("  Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                printAllStudents(students, count);
                break;

            case 3:
                printReport(students, count);
                break;

            case 4: {
                int id, newScore;
                printf("  Enter ID: ");
                scanf("%d", &id);

                printf("  New score: ");
                scanf("%d", &newScore);

                int found = 0;

                for (int i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        updateStudentScore(&students[i], newScore); // POINTER USED HERE
                        found = 1;
                    }
                }

                if (!found)
                    printf("  [!] Student not found.\n");

                break;
            }

            case 5:
                searchStudent(students, count);
                break;

            case 6:
                return 0;

            default:
                printf("  Wrong choice.\n");
        }
    }
}
