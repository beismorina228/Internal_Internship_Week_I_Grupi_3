/*
 * Console-based Student Progress Tracker
 * Internal Internship - Java 1 - Dita 4 - Kerkesa 1
 *
 * Mini-projekt qe menaxhon regjistrime te progresit te nxenesve.
 * Perdor array me madhesi fikse, switch per menu, if/else per validime,
 * loops per shfaqje dhe kontrolle, enum per status, dhe pointer ne funksion.
 */

#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Konstantet dhe tipet                                                 */
/* ------------------------------------------------------------------ */

#define MAX_STUDENTS 5       /* Kapaciteti maksimal i programit */
#define NAME_LEN     50      /* Gjatesia maksimale e emrit      */

/* Enum per statusin e nxenesit */
typedef enum {
    STATUS_ACTIVE   = 0,
    STATUS_PASSED   = 1,
    STATUS_FAILED   = 2
} StudentStatus;

/* Struktura e nje regjistrimi */
typedef struct {
    int           id;
    char          name[NAME_LEN];
    int           score;        /* 0 - 100 */
    StudentStatus status;
} Student;

/* ------------------------------------------------------------------ */
/* Funksionet ndihmese                                                  */
/* ------------------------------------------------------------------ */

/* Kthen emrin e statusit si string */
const char* statusToString(StudentStatus s) {
    switch (s) {
        case STATUS_ACTIVE: return "Active";
        case STATUS_PASSED: return "Passed";
        case STATUS_FAILED: return "Failed";
        default:            return "Unknown";
    }
}

/* Llogarit statusin automatikisht bazuar ne rezultat */
StudentStatus calculateStatus(int score) {
    if (score >= 60) {
        return STATUS_PASSED;
    } else {
        return STATUS_FAILED;
    }
}

/*
 * Funksion me pointer - ploteson te dhenat e nje regjistrimi.
 * Perdor pointer per te modifikuar direkt regjistrimin ne array.
 */
void fillStudent(Student *student, int id, const char *name, int score) {
    student->id     = id;
    strncpy(student->name, name, NAME_LEN - 1);
    student->name[NAME_LEN - 1] = '\0';   /* sigurohemi per null-terminator */
    student->score  = score;
    student->status = calculateStatus(score);
}

/* Shfaq nje regjistrim te vetme ne format te lexueshme */
void printStudent(const Student *student) {
    printf("  ID: %d | Emri: %-20s | Rezultati: %3d | Statusi: %s\n",
           student->id,
           student->name,
           student->score,
           statusToString(student->status));
}

/* Shfaq te gjithe regjistrimet e ruajtura */
void printAllStudents(const Student students[], int count) {
    if (count == 0) {
        printf("\n  [!] Nuk ka asnje regjistrim te ruajtur ende.\n");
        return;
    }

    printf("\n  ============================================================\n");
    printf("  Lista e te gjithe nxenesve te regjistruar (%d/%d):\n",
           count, MAX_STUDENTS);
    printf("  ============================================================\n");

    /* Loop per shfaqjen e te gjithe regjistrimeve */
    for (int i = 0; i < count; i++) {
        printStudent(&students[i]);
    }

    printf("  ============================================================\n");
}

/* Shton nje regjistrim te ri - kthen 1 nese sukses, 0 nese deshtim */
int addStudent(Student students[], int *count) {
    /* Kontrollo nese ka arritur kufirin maksimal */
    if (*count >= MAX_STUDENTS) {
        printf("\n  [!] Kapaciteti maksimal i arritur (%d/%d)."
               " Nuk mund te shtohen me nxenes.\n",
               *count, MAX_STUDENTS);
        return 0;
    }

    char name[NAME_LEN];
    int  score;

    printf("\n  --- Regjistrim i ri ---\n");

    /* Lexo emrin */
    printf("  Emri i nxenesit: ");
    if (scanf(" %49[^\n]", name) != 1) {
        printf("  [!] Input i pavlefshme per emrin.\n");
        return 0;
    }

    /* Lexo dhe valido rezultatin */
    printf("  Rezultati (0-100): ");
    if (scanf("%d", &score) != 1 || score < 0 || score > 100) {
        printf("  [!] Rezultati duhet te jete nje numer ndermjet 0 dhe 100.\n");
        /* Pastro bufferin ne rast inputi te keq */
        while (getchar() != '\n');
        return 0;
    }

    /* Ploteso regjistrimin duke perdorur funksionin me pointer */
    fillStudent(&students[*count], *count + 1, name, score);

    (*count)++;   /* Rrit numrin aktual te regjistrimeve */

    printf("  [OK] Nxenesi '%s' u shtua me sukses (ID: %d).\n",
           name, *count);

    return 1;
}

/* ------------------------------------------------------------------ */
/* Menuja kryesore                                                       */
/* ------------------------------------------------------------------ */

void printMenu(int count) {
    printf("\n  ============================================================\n");
    printf("  STUDENT PROGRESS TRACKER  |  Regjistrime: %d/%d\n",
           count, MAX_STUDENTS);
    printf("  ============================================================\n");
    printf("  1. Shto regjistrim te ri\n");
    printf("  2. Shfaq te gjithe regjistrimet\n");
    printf("  3. Dil nga programi\n");
    printf("  ============================================================\n");
    printf("  Zgjidhni opsionin: ");
}

/* ------------------------------------------------------------------ */
/* Main                                                                  */
/* ------------------------------------------------------------------ */

int main(void) {
    Student students[MAX_STUDENTS];   /* Array me madhesi fikse */
    int     count = 0;                /* Numri aktual i regjistrimeve */
    int     choice;

    printf("\n  Miresevini ne Student Progress Tracker!\n");

    /* Loop kryesor i programit - vazhdon derisa perdoruesi te zgjedhe daljen */
    while (1) {
        printMenu(count);

        if (scanf("%d", &choice) != 1) {
            /* Input jo-numerike - pastro bufferin dhe vazhdo */
            while (getchar() != '\n');
            printf("  [!] Ju lutem shkruani nje numer (1, 2 ose 3).\n");
            continue;
        }

        /* Switch per menaxhimin e zgjedhjes se perdoruesit */
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                printAllStudents(students, count);
                break;

            case 3:
                printf("\n  Mirupafshim! Programi u mbyll.\n\n");
                return 0;

            default:
                printf("  [!] Opsion i pavlefshme. Zgjidhni 1, 2 ose 3.\n");
                break;
        }
    }

    return 0;
}