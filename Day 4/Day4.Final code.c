#include <stdio.h>
#include <string.h>

#define MAX 5
#define NAME_LENGTH 50

enum Status {
    IN_PROGRESS,
    COMPLETED
};

struct Student {
    int id;
    char name[NAME_LENGTH];
    float progress;
    enum Status status;
};

const char* getStatus(enum Status s) {
    return (s == COMPLETED) ? "Completed" : "In Progress";
}

void updateStatus(struct Student *s) {
    if (s->progress >= 70)
        s->status = COMPLETED;
    else
        s->status = IN_PROGRESS;
}

void printStudent(struct Student s) {
    printf("ID: %d | Emri: %s | Progresi: %.2f | Statusi: %s\n",
           s.id, s.name, s.progress, getStatus(s.status));
}

void addStudent(struct Student s[], int *n) {
    if (*n >= MAX) {
        printf("Kapaciteti eshte i plote.\n");
        return;
    }

    printf("Shkruaj ID: ");
    scanf("%d", &s[*n].id);

    printf("Shkruaj emrin: ");
    scanf(" %49[^\n]", s[*n].name);

    printf("Shkruaj progresin (0-100): ");
    scanf("%f", &s[*n].progress);

    if (s[*n].progress < 0)
        s[*n].progress = 0;
    if (s[*n].progress > 100)
        s[*n].progress = 100;

    updateStatus(&s[*n]);
    (*n)++;

    printf("Studenti u shtua me sukses.\n");
}

void showStudents(struct Student s[], int n) {
    if (n == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    printf("\n LISTA E STUDENTEVE \n");
    for (int i = 0; i < n; i++) {
        printStudent(s[i]);
    }
}

void searchStudent(struct Student s[], int n) {
    int choice, id, found = 0;
    char name[NAME_LENGTH];

    printf("\n1. Kerko sipas ID\n");
    printf("2. Kerko sipas emrit\n");
    printf("Zgjedh: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Jep ID: ");
        scanf("%d", &id);

        for (int i = 0; i < n; i++) {
            if (s[i].id == id) {
                printStudent(s[i]);
                found = 1;
                return;
            }
        }
    } else if (choice == 2) {
        printf("Jep emrin: ");
        scanf(" %49[^\n]", name);

        for (int i = 0; i < n; i++) {
            if (strstr(s[i].name, name) != NULL) {
                printStudent(s[i]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("Studenti nuk u gjet.\n");
}

void updateProgress(struct Student s[], int n) {
    int id;

    printf("Jep ID per update: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            printf("Progresi i ri: ");
            scanf("%f", &s[i].progress);

            if (s[i].progress < 0)
                s[i].progress = 0;
            if (s[i].progress > 100)
                s[i].progress = 100;

            updateStatus(&s[i]);
            printf("U perditesua me sukses.\n");
            return;
        }
    }

    printf("ID nuk u gjet.\n");
}

void editStudent(struct Student s[], int n) {
    int id;

    printf("Jep ID per ndryshim: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            printf("Emri i ri: ");
            scanf(" %49[^\n]", s[i].name);

            printf("Progresi i ri: ");
            scanf("%f", &s[i].progress);

            updateStatus(&s[i]);

            printf("Studenti u editua me sukses.\n");
            return;
        }
    }

    printf("ID nuk u gjet.\n");
}

void deleteStudent(struct Student s[], int *n) {
    int id;

    printf("Jep ID per fshirje: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (s[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                s[j] = s[j + 1];
            }

            (*n)--;
            printf("Studenti u fshi me sukses.\n");
            return;
        }
    }

    printf("ID nuk u gjet.\n");
}

void averageProgress(struct Student s[], int n) {
    if (n == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += s[i].progress;
    }

    printf("Mesatarja e progresit: %.2f\n", sum / n);
}

void rankStudents(struct Student s[], int n) {
    if (n == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    printf("\n-RANKING-\n");

    for (int i = 0; i < n; i++) {
        int rank = 1;

        for (int j = 0; j < n; j++) {
            if (s[j].progress > s[i].progress)
                rank++;
        }

        printf("Rank %d -> ", rank);
        printStudent(s[i]);
    }
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
       
        printf(" STUDENT PROGRESS TRACKER FINAL\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Kerko student\n");
        printf("4. Update progres\n");
        printf("5. Edit student\n");
        printf("6. Fshi student\n");
        printf("7. Mesatarja\n");
        printf("8. Ranking\n");
        printf("9. Dil\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateProgress(students, count); break;
            case 5: editStudent(students, count); break;
            case 6: deleteStudent(students, &count); break;
            case 7: averageProgress(students, count); break;
            case 8: rankStudents(students, count); break;
            case 9: printf("Programi po mbyllet.\n"); break;
            default: printf("Opsion i pavlefshem.\n");
        }

    } while(choice != 9);

    return 0;
}