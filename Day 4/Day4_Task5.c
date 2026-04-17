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
    if (n == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nID: %d | %s | %.2f | %s",
               s[i].id,
               s[i].name,
               s[i].progress,
               getStatus(s[i].status));
    }
    printf("\n");
}


void search(struct Student s[], int n) {
    int choice;
    int found = 0;

    printf("\n- KERKIM -\n");
    printf("1. Sipas ID\n2. Sipas Emrit\n");
    printf("Zgjedh: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id;
        printf("Jep ID: ");
        scanf("%d", &id);

        for (int i = 0; i < n; i++) {
            if (s[i].id == id) {
                found = 1;

                printf("\nGJETUR: %s | %.2f | %s\n",
                       s[i].name,
                       s[i].progress,
                       getStatus(s[i].status));

                
                if (s[i].progress < 40 && s[i].status == IN_PROGRESS) {
                    printf("PARALAJMERIM: Progres shume i ulet!\n");
                }
                else if (s[i].progress >= 40 && s[i].progress < 70) {
                    printf("REKOMANDIM: Vazhdoni punen, jeni ne mes!\n");
                }
                else if (s[i].progress >= 90) {
                    printf("SHUME MIRE: Performancë e lartë!\n");
                }

                return;
            }
        }
    }
    else if (choice == 2) {
        char name[50];
        printf("Jep emrin (ose pjese te emrit): ");
        scanf(" %49[^\n]", name);

        for (int i = 0; i < n; i++) {
            if (strstr(s[i].name, name) != NULL) {
                found = 1;

                printf("\nGJETUR: %s | %.2f | %s\n",
                       s[i].name,
                       s[i].progress,
                       getStatus(s[i].status));

              
                       if (s[i].progress < 50 && s[i].status == IN_PROGRESS) {
                    printf("KUJDES: Studenti eshte prapa.\n");
                }
                else if (s[i].progress >= 50 && s[i].progress < 80) {
                    printf("OK: Progres stabil.\n");
                }
                else if (s[i].progress >= 80) {
                    printf("SHKELQYES: Performancë e lartë.\n");
                }
            }
        }
    }

    if (!found) {
        printf("Asnje regjistrim nuk u gjet.\n");
    }
}


int main() {
    struct Student s[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n- TASK 5 -\n");
        printf("1 Shto\n2 Shfaq\n3 Kerko (SMART)\n4 Dil\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add(s, &n); break;
            case 2: show(s, n); break;
            case 3: search(s, n); break;
        }

    } while(choice != 4);

    return 0;
}