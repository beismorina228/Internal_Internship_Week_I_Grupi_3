/*
 * Console-based Student Progress Tracker
 * Internal Internship - Java 1 - Dita 4 - Kerkesa 2
 *
 * Zgjerime nga Kerkesa 1:
 * - Perdoruesi zgjedh statusin manualisht (jo me automatik nga score)
 * - Switch i dyte per zgjedhjen e statusit
 * - Validim me i forte i te gjitha input-eve
 * - Enum perdoret realisht ne menaxhimin e rrjedhes se programit
 */

#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Konstantet dhe tipet                                                 */
/* ------------------------------------------------------------------ */

#define MAX_STUDENTS 5       /* Kapaciteti maksimal i programit */
#define NAME_LEN     50      /* Gjatesia maksimale e emrit      */

/* Enum per statusin e nxenesit - perdoret realisht ne logjike */
typedef enum {
    STATUS_ACTIVE = 0,
    STATUS_PASSED = 1,
    STATUS_FAILED = 2
} StudentStatus;

/* Struktura e nje regjistrimi */
typedef struct {
    int           id;
    char          name[NAME_LEN];
    int           score;        /* 0 - 100 */
    StudentStatus status;
} Student;

/* ------------------------------------------------------------------ */
/* Funksionet ndihmese per enum dhe shfaqje                             */
/* ------------------------------------------------------------------ */

/* Kthen emrin e statusit si string - switch i brendshem */
const char* statusToString(StudentStatus s) {
    switch (s) {
        case STATUS_ACTIVE: return "Active";
        case STATUS_PASSED: return "Passed";
        case STATUS_FAILED: return "Failed";
        default:            return "Unknown";
    }
}

/*
 * Kerkon perdoruesin te zgjedhe statusin manualisht.
 * Perdor switch te dyte per degezim te qarte.
 * Kthen 1 nese zgjedhja eshte e vlefshme, 0 nese jo.
 */
int chooseStatus(StudentStatus *outStatus) {
    int choice;

    printf("  Zgjidhni statusin:\n");
    printf("    1. Active  (nxenesi eshte ne progres)\n");
    printf("    2. Passed  (nxenesi ka kaluar)\n");
    printf("    3. Failed  (nxenesi ka deshtuar)\n");
    printf("  Zgjedhja juaj: ");

    if (scanf("%d", &choice) != 1) {
        /* Input jo-numerike - pastro bufferin */
        while (getchar() != '\n');
        printf("  [!] Input i pavlefshme. Duhet te shkruani 1, 2 ose 3.\n");
        return 0;
    }

    /* Switch i dyte - per zgjedhjen e statusit */
    switch (choice) {
        case 1:
            *outStatus = STATUS_ACTIVE;
            return 1;
        case 2:
            *outStatus = STATUS_PASSED;
            return 1;
        case 3:
            *outStatus = STATUS_FAILED;
            return 1;
        default:
            printf("  [!] Zgjedhje e pavlefshme per statusin. Duhet te jete 1, 2 ose 3.\n");
            return 0;
    }
}

/* ------------------------------------------------------------------ */
/* Funksionet per regjistrimet                                          */
/* ------------------------------------------------------------------ */

/*
 * Funksion me pointer - ploteson te dhenat e nje regjistrimi.
 * Perdor pointer per te modifikuar direkt regjistrimin ne array.
 * Tani merr statusin si parameter (zgjedhur manualisht nga perdoruesi).
 */
void fillStudent(Student *student, int id, const char *name,
                 int score, StudentStatus status) {
    student->id     = id;
    strncpy(student->name, name, NAME_LEN - 1);
    student->name[NAME_LEN - 1] = '\0';
    student->score  = score;
    student->status = status;
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

    char          name[NAME_LEN];
    int           score;
    StudentStatus status;

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
        while (getchar() != '\n');
        return 0;
    }

    /* Perdoruesi zgjedh statusin manualisht - me switch te brendshem */
    if (chooseStatus(&status) == 0) {
        /* Zgjedhja e statusit deshtoi - mos shto regjistrimin */
        return 0;
    }

    /* Ploteso regjistrimin duke perdorur funksionin me pointer */
    fillStudent(&students[*count], *count + 1, name, score, status);

    (*count)++;

    printf("  [OK] Nxenesi '%s' u shtua me sukses (ID: %d, Statusi: %s).\n",
           name, *count, statusToString(students[*count - 1].status));

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

    /* Loop kryesor i programit */
    while (1) {
        printMenu(count);

        if (scanf("%d", &choice) != 1) {
            /* Input jo-numerike - pastro bufferin dhe vazhdo */
            while (getchar() != '\n');
            printf("  [!] Ju lutem shkruani nje numer (1, 2 ose 3).\n");
            continue;
        }

        /* Switch kryesor per menaxhimin e zgjedhjes se perdoruesit */
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
