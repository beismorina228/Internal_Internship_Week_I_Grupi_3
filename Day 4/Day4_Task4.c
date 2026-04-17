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
    for (int i = 0; i < n; i++) {
        printf("\nID: %d | %s | %.2f | %s",
               s[i].id,
               s[i].name,
               s[i].progress,
               getStatus(s[i].status));
    }
    printf("\n");
}

void updateProgress(struct Student *s) {
    float newProgress;

    printf("Progresi i ri: ");
    scanf("%f", &newProgress);

    
    s->progress = newProgress;

    if (s->progress >= 70)
        s->status = COMPLETED;
    else
        s->status = IN_PROGRESS;

    printf("U perditesua me sukses!\n");
}


void findAndUpdate(struct Student s[], int n) {
    int id;

    printf("Jep ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {

            printf("Gjetur: %s | %.2f\n", s[i].name, s[i].progress);

            
            updateProgress(&s[i]);

            return;
        }
    }

    printf("Nuk u gjet studenti.\n");
}


int main() {
    struct Student s[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n- TASK 4 -\n");
        printf("1 Shto\n2 Shfaq\n3 Update progres (POINTER)\n4 Dil\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add(s, &n); break;
            case 2: show(s, n); break;
            case 3: findAndUpdate(s, n); break;
        }

    } while(choice != 4);

    return 0;
}
