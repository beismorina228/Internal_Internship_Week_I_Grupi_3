#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

struct ProgressRecord {
    char studentName[50];
    char courseName[50];
    int score;
    char status[30];
};

void calculateStatus(int score, char status[]) {
    if (score >= 90) {
        strcpy(status, "Shkelqyeshem");
    } else if (score >= 70) {
        strcpy(status, "Mire");
    } else if (score >= 50) {
        strcpy(status, "Ne progres");
    } else {
        strcpy(status, "Ka nevoje per permisim");
    }
}

void displayRecord(struct ProgressRecord record, int index) {
    printf("\nRegjistrimi #%d\n", index + 1);
    printf("Emri i nxenesit: %s\n", record.studentName);
    printf("Kursi: %s\n", record.courseName);
    printf("Piket: %d\n", record.score);
    printf("Statusi: %s\n", record.status);
    printf("------------------------------\n");
}

int main() {
    struct ProgressRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENYJA E PROGRAMIT =====\n");
        printf("1. Shto regjistrim te ri\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedh opsionin: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (count >= MAX_RECORDS) {
                    printf("Nuk mund te shtoni me regjistrime. Eshte arritur maksimumi.\n");
                } else {
                    printf("Shkruaj emrin e nxenesit: ");
                    fgets(records[count].studentName, sizeof(records[count].studentName), stdin);
                    records[count].studentName[strcspn(records[count].studentName, "\n")] = 0;

                    printf("Shkruaj emrin e kursit: ");
                    fgets(records[count].courseName, sizeof(records[count].courseName), stdin);
                    records[count].courseName[strcspn(records[count].courseName, "\n")] = 0;

                    printf("Shkruaj piket: ");
                    scanf("%d", &records[count].score);
                    getchar();

                    calculateStatus(records[count].score, records[count].status);

                    count++;

                    printf("Regjistrimi u shtua me sukses.\n");
                    printf("Numri aktual i regjistrimeve: %d/%d\n", count, MAX_RECORDS);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Nuk ka ende regjistrime te ruajtura.\n");
                } else {
                    printf("\n===== TE GJITHA REGJISTRIMET =====\n");
                    for (int i = 0; i < count; i++) {
                        displayRecord(records[i], i);
                    }
                    printf("Gjithsej regjistrime: %d/%d\n", count, MAX_RECORDS);
                }
                break;

            case 3:
                printf("Programi po mbyllet...\n");
                break;

            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 3);

    return 0;
}