#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

enum Status {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED
};

struct ProgressRecord {
    char studentName[50];
    char courseName[50];
    int score;
    enum Status status;
};

void clearInputBuffer() {
    while (getchar() != '\n');
}

const char* getStatusText(enum Status status) {
    switch (status) {
        case BEGINNER:
            return "Beginner";
        case INTERMEDIATE:
            return "Intermediate";
        case ADVANCED:
            return "Advanced";
        default:
            return "Unknown";
    }
}

int readInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Input i pavlefshem. Ju lutem shkruani nje numer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

enum Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nZgjedh statusin:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("Zgjedhja juaj: ");

        choice = readInt();

        switch (choice) {
            case 1:
                return BEGINNER;
            case 2:
                return INTERMEDIATE;
            case 3:
                return ADVANCED;
            default:
                printf("Status i pavlefshem. Provo perseri.\n");
        }
    }
}

void addRecord(struct ProgressRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Nuk mund te shtoni me regjistrime. Eshte arritur maksimumi.\n");
        return;
    }

    printf("Shkruaj emrin e nxenesit: ");
    fgets(records[*count].studentName, sizeof(records[*count].studentName), stdin);
    records[*count].studentName[strcspn(records[*count].studentName, "\n")] = '\0';

    printf("Shkruaj emrin e kursit: ");
    fgets(records[*count].courseName, sizeof(records[*count].courseName), stdin);
    records[*count].courseName[strcspn(records[*count].courseName, "\n")] = '\0';

    printf("Shkruaj piket: ");
    records[*count].score = readInt();

    records[*count].status = chooseStatus();

    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Numri aktual i regjistrimeve: %d/%d\n", *count, MAX_RECORDS);
}

void displayAllRecords(struct ProgressRecord records[], int count) {
    if (count == 0) {
        printf("Nuk ka ende regjistrime te ruajtura.\n");
        return;
    }

    printf("\n===== TE GJITHA REGJISTRIMET =====\n");
    for (int i = 0; i < count; i++) {
        printf("\nRegjistrimi #%d\n", i + 1);
        printf("Emri i nxenesit: %s\n", records[i].studentName);
        printf("Kursi: %s\n", records[i].courseName);
        printf("Piket: %d\n", records[i].score);
        printf("Statusi: %s\n", getStatusText(records[i].status));
        printf("------------------------------\n");
    }

    printf("Gjithsej regjistrime: %d/%d\n", count, MAX_RECORDS);
}

int main() {
    struct ProgressRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENYJA KRYESORE =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedh opsionin: ");

        choice = readInt();

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayAllRecords(records, count);
                break;
            case 3:
                printf("Programi po mbyllet...\n");
                break;
            default:
                printf("Opsion i pavlefshem. Ju lutem zgjidhni 1, 2 ose 3.\n");
        }

    } while (choice != 3);

    return 0;
}