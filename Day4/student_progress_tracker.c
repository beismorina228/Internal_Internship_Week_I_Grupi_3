/*
 * Console-based Student Progress Tracker
 * Internal Internship - Java 1 - Dita 4
 */

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

/* ================= HELPERS ================= */
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

/* ================= CORE FUNCTIONS ================= */
void fillStudent(Student *s, int id, const char *name, int score, StudentStatus status) {
    s->id = id;
    strncpy(s->name, name, NAME_LEN - 1);
    s->name[NAME_LEN - 1] = '\0';
    s->score = score;
    s->status = status;
}

void printStudent(const Student *s) {
    printf("  ID: %d | Emri: %-15s | Score: %3d | Status: %s\n",
           s->id, s->name, s->score, statusToString(s->status));
}

void printAllStudents(const Student students[], int count) {
    if (count == 0) {
        printf("\n  [!] Nuk ka regjistrime.\n");
        return;
    }

    printf("\n  ===== STUDENT LIST =====\n");
    for (int i = 0; i < count; i++) {
        printStudent(&students[i]);
    }
}

/* ================= TASK 3: REPORT ================= */
void printReport(const Student students[], int count) {
    printf("\n  ===== ANALYTICAL REPORT =====\n");

    if (count == 0) {
        printf("  No data available.\n");
        return;
    }

    int sum = 0;
    int max = students[0].score;
    int min = students[0].score;

    int passed = 0, failed = 0, active = 0;

    for (int i = 0; i < count; i++) {
        int score = students[i].score;
        sum += score;

        if (score > max) max = score;
        if (score < min) min = score;

        if (students[i].status == STATUS_PASSED) passed++;
        else if (students[i].status == STATUS_FAILED) failed++;
        else active++;
    }

    float avg = (float)sum / count;

    printf("  Total students : %d\n", count);
    printf("  Passed         : %d\n", passed);
    printf("  Failed         : %d\n", failed);
    printf("  Active         : %d\n", active);
    printf("  Average score  : %.2f\n", avg);
    printf("  Max score      : %d\n", max);
    printf("  Min score      : %d\n", min);

    printf("  Performance    : ");

    if (avg >= 85) printf("Excellent\n");
    else if (avg >= 70) printf("Good\n");
    else if (avg >= 50) printf("Average\n");
    else printf("Poor\n");
}

/* ================= TASK 4: SEARCH + FILTER ================= */
void searchStudent(const Student students[], int count) {
    if (count == 0) {
        printf("\n  [!] Nuk ka te dhena per kerkim.\n");
        return;
    }

    int choice;

    printf("\n  ===== SEARCH MENU =====\n");
    printf("  1. Search by ID\n");
    printf("  2. Search by Name\n");
    printf("  Zgjedhja: ");

    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("  [!] Input i pavlefshem.\n");
        return;
    }

    if (choice == 1) {
        int id;
        printf("  Shkruaj ID: ");

        if (scanf("%d", &id) != 1) {
            printf("  [!] ID e pavlefshme.\n");
            return;
        }

        int found = 0;

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                found = 1;

                printf("\n  ===== RESULT =====\n");
                printStudent(&students[i]);

                /* SMART LOGIC */
                if (students[i].score < 50 && students[i].status != STATUS_FAILED) {
                    printf("  [!] WARNING: Low score but not marked failed.\n");
                } else if (students[i].score >= 90 && students[i].status == STATUS_ACTIVE) {
                    printf("  [!] NOTE: High performer still active.\n");
                } else {
                    printf("  [OK] Data is consistent.\n");
                }
            }
        }

        if (!found) {
            printf("  [!] Nuk u gjet student me kete ID.\n");
        }

    } else if (choice == 2) {
        char name[NAME_LEN];
        printf("  Shkruaj emrin: ");
        scanf(" %49[^\n]", name);

        int found = 0;

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                found = 1;

                printf("\n  ===== RESULT =====\n");
                printStudent(&students[i]);

                /* SMART LOGIC */
                if (students[i].score < 50) {
                    printf("  [!] WARNING: Very low performance.\n");
                } else if (students[i].score >= 90) {
                    printf("  [!] RECOMMENDATION: Excellent student.\n");
                } else {
                    printf("  [OK] Normal performance.\n");
                }
            }
        }

        if (!found) {
            printf("  [!] Nuk u gjet student me kete emer.\n");
        }

    } else {
        printf("  [!] Zgjedhje e pavlefshme.\n");
    }
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

    fillStudent(&students[*count], *count + 1, name, score, status);
    (*count)++;

    printf("  [OK] Shtuar me sukses!\n");
    return 1;
}

/* ================= MENU ================= */
void printMenu(int count) {
    printf("\n  ===== MENU (%d/%d) =====\n", count, MAX_STUDENTS);
    printf("  1. Add student\n");
    printf("  2. Show students\n");
    printf("  3. Show report\n");
    printf("  4. Search student\n");
    printf("  5. Exit\n");
    printf("  Zgjedhja: ");
}

/* ================= MAIN ================= */
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printMenu(count);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("  [!] Input i pavlefshem.\n");
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

            case 4:
                searchStudent(students, count);
                break;

            case 5:
                printf("  Exit...\n");
                return 0;

            default:
                printf("  [!] Zgjedhje e pavlefshme.\n");
        }
    }
}
