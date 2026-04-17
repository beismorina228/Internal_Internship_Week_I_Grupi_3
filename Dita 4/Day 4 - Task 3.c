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

int readInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Input i pavlefshem. Ju lutem shkruani nje numer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
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

void showReport(struct ProgressRecord records[], int count) {
    if (count == 0) {
        printf("\n===== RAPORTI ANALITIK =====\n");
        printf("Nuk ka regjistrime per analizim.\n");
        return;
    }

    int totalScore = 0;
    int highestScore = records[0].score;
    int lowestScore = records[0].score;
    int advancedCount = 0;

    for (int i = 0; i < count; i++) {
        totalScore += records[i].score;

        if (records[i].score > highestScore) {
            highestScore = records[i].score;
        }

        if (records[i].score < lowestScore) {
            lowestScore = records[i].score;
        }

        if (records[i].status == ADVANCED) {
            advancedCount++;
        }
    }

    float average = (float) totalScore / count;

    printf("\n===== RAPORTI ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i rasteve Advanced: %d\n", advancedCount);
    printf("Mesatarja e pikeve: %.2f\n", average);
    printf("Piket me te larta: %d\n", highestScore);
    printf("Piket me te ulta: %d\n", lowestScore);

    printf("\nKlasifikimi i rezultateve:\n");

    if (average >= 85) {
        printf("Performanca e pergjithshme eshte shume e mire.\n");
    } else if (average >= 65) {
        printf("Performanca e pergjithshme eshte e kenaqshme.\n");
    } else {
        printf("Performanca e pergjithshme ka nevoje per permiresim.\n");
    }

    if (advancedCount == count) {
        printf("Te gjitha regjistrimet jane ne nivel Advanced.\n");
    } else if (advancedCount > 0) {
        printf("Disa regjistrime kane arritur nivelin Advanced.\n");
    } else {
        printf("Asnje regjistrim nuk eshte ne nivelin Advanced.\n");
    }
}

int main() {
    struct ProgressRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENYJA KRYESORE =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Shfaq raportin analitik\n");
        printf("4. Dil\n");
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
                showReport(records, count);
                break;
            case 4:
                printf("Programi po mbyllet...\n");
                break;
            default:
                printf("Opsion i pavlefshem. Ju lutem zgjidhni 1, 2, 3 ose 4.\n");
        }

    } while (choice != 4);

    return 0;
}