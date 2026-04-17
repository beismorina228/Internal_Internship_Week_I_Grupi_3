#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status {
    IN_PROGRESS,
    COMPLETED
};

struct Student {
    int id;
    char name[50];
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
           s.id,
           s.name,
           s.progress,
           getStatus(s.status));
}

void add(struct Student s[], int *n) {
    if (*n >= MAX) {
        printf("Kapacitet i plote.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &s[*n].id);

    printf("Emri: ");
    scanf(" %49[^\n]", s[*n].name);

    printf("Progresi: ");
    scanf("%f", &s[*n].progress);

    updateStatus(&s[*n]);
    (*n)++;
}

void show(struct Student s[], int n) {
    if (n == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    printf("\n===== LISTA E STUDENTEVE =====\n");

    for (int i = 0; i < n; i++) {
        printStudent(s[i]);
    }
}

void search(struct Student s[], int n) {
    int id;
    int found = 0;

    printf("Jep ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            found = 1;

            printf("\n===== STUDENTI U GJET =====\n");
            printStudent(s[i]);

            if (s[i].progress < 40)
                printf("PARALAJMERIM: Progres i ulet.\n");

            return;
        }
    }

    if (!found)
        printf("Asnje regjistrim nuk u gjet.\n");
}

void rankStudents(struct Student s[], int n) {
    if (n == 0) {
        printf("Nuk ka te dhena per rankim.\n");
        return;
    }

    printf("\n===== RANKING FINAL =====\n");

    for (int i = 0; i < n; i++) {
        int rank = 1;

        for (int j = 0; j < n; j++) {
            if (s[j].progress > s[i].progress) {
                rank++;
            }
        }

        printf("Rank %d -> ", rank);
        printStudent(s[i]);
    }
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

            printf("U perditesua me sukses.\n");
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
            printf("U fshi me sukses.\n");
            return;
        }
    }

    printf("ID nuk u gjet.\n");
}

int main() {
    struct Student s[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n==============================\n");
        printf(" STUDENT PROGRESS TRACKER\n");
        printf("==============================\n");
        printf("1 Shto\n");
        printf("2 Shfaq\n");
        printf("3 Kerko\n");
        printf("4 Ranking\n");
        printf("5 Ndrysho student\n");
        printf("6 Fshi student\n");
        printf("7 Dil\n");
        printf("==============================\n");
        printf("Zgjedh: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: add(s, &n); break;
            case 2: show(s, n); break;
            case 3: search(s, n); break;
            case 4: rankStudents(s, n); break;
            case 5: editStudent(s, n); break;
            case 6: deleteStudent(s, &n); break;
            case 7: printf("Programi po mbyllet.\n"); break;
            default: printf("Opsion i pavlefshem.\n");
        }

    } while(choice != 7);

    return 0;
}