#include <stdio.h>
#include <string.h>

/* ============================================================
   STUDENT MANAGEMENT SYSTEM
   Tasks covered: 1-8
   ============================================================ */

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define SEPARATOR "  +---------+----------------------+-------+----------+"
#define LINE      "  |---------|----------------------|-------|----------|"

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

/* ============================================================
   UTILITY FUNCTIONS
   ============================================================ */

const char* statusToString(StudentStatus s) {
    switch (s) {
        case STATUS_ACTIVE: return "Active";
        case STATUS_PASSED: return "Passed";
        case STATUS_FAILED: return "Failed";
        default:            return "Unknown";
    }
}

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printHeader(void) {
    printf("%s\n", SEPARATOR);
    printf("  | %-7s | %-20s | %-5s | %-8s |\n", "ID", "Name", "Score", "Status");
    printf("%s\n", LINE);
}

void printFooter(void) {
    printf("%s\n", SEPARATOR);
}

void printStudentRow(const Student *s) {
    printf("  | %-7d | %-20s | %-5d | %-8s |\n",
           s->id, s->name, s->score, statusToString(s->status));
}

/* Returns 1 on valid status choice, 0 otherwise */
int chooseStatus(StudentStatus *outStatus) {
    int choice;
    printf("  Status  1=Active  2=Passed  3=Failed : ");
    if (scanf("%d", &choice) != 1) { clearBuffer(); return 0; }
    switch (choice) {
        case 1: *outStatus = STATUS_ACTIVE;  return 1;
        case 2: *outStatus = STATUS_PASSED;  return 1;
        case 3: *outStatus = STATUS_FAILED;  return 1;
        default: printf("  [!] Status i pavlefshem.\n"); return 0;
    }
}

/* Auto-set status based on score */
StudentStatus scoreToStatus(int score) {
    if (score >= 80) return STATUS_PASSED;
    if (score <  50) return STATUS_FAILED;
    return STATUS_ACTIVE;
}

/* Find student index by ID, returns -1 if not found */
int findById(Student students[], int count, int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return i;
    return -1;
}

/* ============================================================
   TASK 4 — UPDATE SCORE VIA POINTER
   ============================================================ */
void updateStudentScore(Student *s, int newScore) {
    if (newScore < 0 || newScore > 100) {
        printf("  [!] Score duhet te jete 0-100.\n");
        return;
    }
    s->score  = newScore;
    s->status = scoreToStatus(newScore);
    printf("  [OK] Score u perditesua. Status i ri: %s\n",
           statusToString(s->status));
}

/* ============================================================
   TASK 1 — ADD STUDENT
   ============================================================ */
int addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n  [!] Lista eshte plot (%d/%d).\n", *count, MAX_STUDENTS);
        return 0;
    }

    char name[NAME_LEN];
    int  score;
    StudentStatus status;

    printf("\n  --- Shto Student ---\n");
    printf("  Emri   : ");
    if (scanf(" %49[^\n]", name) != 1) { clearBuffer(); return 0; }

    printf("  Score  : ");
    if (scanf("%d", &score) != 1 || score < 0 || score > 100) {
        printf("  [!] Score i pavlefshem (0-100).\n");
        clearBuffer();
        return 0;
    }

    if (!chooseStatus(&status)) return 0;

    Student *s = &students[*count];
    s->id     = (*count == 0) ? 1 : students[*count - 1].id + 1;
    strncpy(s->name, name, NAME_LEN - 1);
    s->name[NAME_LEN - 1] = '\0';
    s->score  = score;
    s->status = status;
    (*count)++;

    printf("  [OK] Studenti u shtua me ID: %d\n", s->id);
    return 1;
}

/* ============================================================
   TASK 2 — SHOW ALL
   ============================================================ */
void printAllStudents(const Student students[], int count) {
    printf("\n  ===== LISTA E STUDENTEVE (%d) =====\n", count);
    if (count == 0) { printf("  [!] Nuk ka regjistrime.\n"); return; }
    printHeader();
    for (int i = 0; i < count; i++) printStudentRow(&students[i]);
    printFooter();
}

/* ============================================================
   TASK 3 — REPORT
   ============================================================ */
void printReport(const Student students[], int count) {
    printf("\n  ===== RAPORT =====\n");
    if (count == 0) { printf("  [!] Nuk ka te dhena.\n"); return; }

    int sum = 0, maxS = students[0].score, minS = students[0].score;
    int passed = 0, failed = 0, active = 0;

    for (int i = 0; i < count; i++) {
        int sc = students[i].score;
        sum += sc;
        if (sc > maxS) maxS = sc;
        if (sc < minS) minS = sc;
        if (students[i].status == STATUS_PASSED)      passed++;
        else if (students[i].status == STATUS_FAILED) failed++;
        else                                           active++;
    }

    printf("  Total studentet : %d\n", count);
    printf("  Passed          : %d\n", passed);
    printf("  Failed          : %d\n", failed);
    printf("  Active          : %d\n", active);
    printf("  Mesatarja       : %.2f\n", (float)sum / count);
    printf("  Maksimumi       : %d\n", maxS);
    printf("  Minimumi        : %d\n", minS);
}

/* ============================================================
   TASK 5 — SEARCH WITH WARNINGS
   ============================================================ */
void printWarning(const Student *s) {
    if (s->score < 50 && s->status != STATUS_FAILED)
        printf("  [!] WARNING: Score i ulet por statusi nuk eshte Failed!\n");
    else if (s->score >= 90 && s->status == STATUS_ACTIVE)
        printf("  [!] NOTE: Score shkelqyes por statusi eshte Active!\n");
    else if (s->score < 50)
        printf("  [!] WARNING: Performanse e dobet!\n");
    else if (s->score >= 90)
        printf("  [!] RECOMMENDATION: Student shkelqyes!\n");
    else
        printf("  [OK] Te dhenat jane OK.\n");
}

void searchStudent(Student students[], int count) {
    if (count == 0) { printf("\n  [!] Nuk ka te dhena.\n"); return; }

    int choice;
    printf("\n  Kerko:  1=sipas ID   2=sipas Emrit\n  Zgjedhja: ");
    if (scanf("%d", &choice) != 1) { clearBuffer(); return; }

    if (choice == 1) {
        int id;
        printf("  ID: ");
        if (scanf("%d", &id) != 1) { clearBuffer(); return; }
        int idx = findById(students, count, id);
        if (idx == -1) { printf("  [!] Studenti nuk u gjet.\n"); return; }
        printf("\n"); printHeader();
        printStudentRow(&students[idx]);
        printFooter();
        printWarning(&students[idx]);

    } else if (choice == 2) {
        char name[NAME_LEN];
        printf("  Emri: ");
        if (scanf(" %49[^\n]", name) != 1) { clearBuffer(); return; }

        int found = 0;
        printf("\n"); printHeader();
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printStudentRow(&students[i]);
                found++;
            }
        }
        printFooter();
        if (!found) printf("  [!] Studenti nuk u gjet.\n");
    } else {
        printf("  [!] Zgjedhje e pavlefshme.\n");
    }
}

/* ============================================================
   TASK 6 — SORT / RANK
   ============================================================ */
void printRanking(const Student students[], int count) {
    if (count == 0) { printf("\n  [!] Nuk ka te dhena per renditje.\n"); return; }

    /* Copy to temp array so we don't disturb the original order */
    Student temp[MAX_STUDENTS];
    for (int i = 0; i < count; i++) temp[i] = students[i];

    /* Bubble sort descending by score */
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (temp[j].score < temp[j+1].score) {
                Student t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }

    printf("\n  ===== RENDITJA SIPAS SCORES (mire -> keq) =====\n");
    printf("%s\n", SEPARATOR);
    printf("  | %-7s | %-20s | %-5s | %-8s |\n", "Rank", "Name", "Score", "Status");
    printf("%s\n", LINE);
    for (int i = 0; i < count; i++) {
        printf("  | %-7d | %-20s | %-5d | %-8s |\n",
               i + 1, temp[i].name, temp[i].score, statusToString(temp[i].status));
    }
    printFooter();
}

/* ============================================================
   TASK 7 — EDIT & DELETE
   ============================================================ */
void editStudent(Student students[], int count) {
    if (count == 0) { printf("\n  [!] Nuk ka te dhena.\n"); return; }

    int id;
    printf("\n  Fut ID-ne e studentit per modifikim: ");
    if (scanf("%d", &id) != 1) { clearBuffer(); return; }

    int idx = findById(students, count, id);
    if (idx == -1) { printf("  [!] Studenti nuk u gjet.\n"); return; }

    Student *s = &students[idx];
    printf("  Studenti aktual: %s | Score: %d | Status: %s\n",
           s->name, s->score, statusToString(s->status));

    printf("\n  Cfare deshironi te ndryshoni?\n");
    printf("  1. Emrin\n");
    printf("  2. Score\n");
    printf("  3. Emrin dhe Score\n");
    printf("  Zgjedhja: ");

    int choice;
    if (scanf("%d", &choice) != 1) { clearBuffer(); return; }

    if (choice == 1 || choice == 3) {
        char name[NAME_LEN];
        printf("  Emri i ri: ");
        if (scanf(" %49[^\n]", name) != 1) { clearBuffer(); return; }
        strncpy(s->name, name, NAME_LEN - 1);
        s->name[NAME_LEN - 1] = '\0';
        printf("  [OK] Emri u ndryshua.\n");
    }

    if (choice == 2 || choice == 3) {
        int newScore;
        printf("  Score i ri (0-100): ");
        if (scanf("%d", &newScore) != 1) { clearBuffer(); return; }
        updateStudentScore(s, newScore);   /* reuses pointer task */
    }

    if (choice < 1 || choice > 3)
        printf("  [!] Zgjedhje e pavlefshme.\n");
}

void deleteStudent(Student students[], int *count) {
    if (*count == 0) { printf("\n  [!] Nuk ka te dhena.\n"); return; }

    int id;
    printf("\n  Fut ID-ne e studentit per fshirje: ");
    if (scanf("%d", &id) != 1) { clearBuffer(); return; }

    int idx = findById(students, *count, id);
    if (idx == -1) { printf("  [!] Studenti nuk u gjet.\n"); return; }

    printf("  Konfirmoni fshirjen e '%s'? (1=Po / 0=Jo): ", students[idx].name);
    int confirm;
    if (scanf("%d", &confirm) != 1 || confirm != 1) {
        printf("  [!] Fshirja u anullua.\n");
        return;
    }

    /* Shift elements left to fill the gap */
    for (int i = idx; i < *count - 1; i++)
        students[i] = students[i + 1];

    (*count)--;
    printf("  [OK] Studenti u fshi. Total: %d\n", *count);
}

/* ============================================================
   MENU
   ============================================================ */
void printMenu(int count) {
    printf("\n+----------------------------------+\n");
    printf("|   STUDENT MANAGEMENT SYSTEM      |\n");
    printf("|   Studentet: %2d / %-2d              |\n", count, MAX_STUDENTS);
    printf("+----------------------------------+\n");
    printf("| 1. Shto student                  |\n");
    printf("| 2. Shfaq te gjithe                |\n");
    printf("| 3. Raport                         |\n");
    printf("| 4. Perditeso score (me pointer)   |\n");
    printf("| 5. Kerko student                  |\n");
    printf("| 6. Rendit / Rank                  |\n");
    printf("| 7. Modifiko student               |\n");
    printf("| 8. Fshi student                   |\n");
    printf("| 0. Dil                            |\n");
    printf("+----------------------------------+\n");
    printf("  Zgjedhja: ");
}

/* ============================================================
   MAIN
   ============================================================ */
int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("\n  Miresevini ne Student Management System!\n");

    while (1) {
        printMenu(count);

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("  [!] Input i pavlefshem.\n");
            continue;
        }

        switch (choice) {
            case 1: addStudent(students, &count);       break;
            case 2: printAllStudents(students, count);  break;
            case 3: printReport(students, count);       break;

            case 4: {
                if (count == 0) { printf("\n  [!] Nuk ka studentet.\n"); break; }
                int id, newScore;
                printf("  ID       : "); scanf("%d", &id);
                printf("  Score i ri: "); scanf("%d", &newScore);
                int idx = findById(students, count, id);
                if (idx == -1) printf("  [!] Studenti nuk u gjet.\n");
                else           updateStudentScore(&students[idx], newScore);
                break;
            }

            case 5: searchStudent(students, count);     break;
            case 6: printRanking(students, count);      break;
            case 7: editStudent(students, count);       break;
            case 8: deleteStudent(students, &count);    break;

            case 0:
                printf("\n  Mirupafshim!\n\n");
                return 0;

            default:
                printf("  [!] Zgjedhje e gabuar (0-8).\n");
        }
    }
}
