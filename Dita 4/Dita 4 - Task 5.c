#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 5

enum Status {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED
};

struct ProgressRecord {
    int id;
    char studentName[50];
    int progress;
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

int idExists(struct ProgressRecord records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void printWarningMessage(struct ProgressRecord record) {
    printf("Vleresimi i programit: ");

    if (record.progress < 50 && record.status == BEGINNER) {
        printf("Paralajmerim - progres shume i ulet dhe status fillestar. Kerkohet me shume ushtrim.\n");
    } else if (record.progress < 50 && record.status == INTERMEDIATE) {
        printf("Rezultati eshte i ulet per nivelin aktual. Rekomandohet perseritje e materialit.\n");
    } else if (record.progress >= 50 && record.progress < 70 && record.status == BEGINNER) {
        printf("Ka permiresim, por nxenesi ende ka nevoje per ushtrime shtese.\n");
    } else if (record.progress >= 70 && record.progress < 85 && record.status == INTERMEDIATE) {
        printf("Performanca eshte e mire. Nxenesi eshte ne rrugen e duhur.\n");
    } else if (record.progress >= 85 && record.status == ADVANCED) {
        printf("Shume mire - performanca eshte e larte dhe perputhet me statusin Advanced.\n");
    } else if (record.progress >= 85 && record.status != ADVANCED) {
        printf("Rezultat shume i mire. Mund te konsiderohet ngritja ne nje status me te larte.\n");
    } else {
        printf("Regjistrimi eshte ne gjendje stabile, por duhet vazhduar puna rregullisht.\n");
    }
}

void displaySingleRecord(struct ProgressRecord record, int index) {
    printf("\nRegjistrimi #%d\n", index + 1);
    printf("ID: %d\n", record.id);
    printf("Emri: %s\n", record.studentName);
    printf("Progresi / Rezultati: %d\n", record.progress);
    printf("Statusi: %s\n", getStatusText(record.status));
    printWarningMessage(record);
    printf("------------------------------\n");
}

void addRecord(struct ProgressRecord records[], int *count) {
    int newId;

    if (*count >= MAX_RECORDS) {
        printf("Nuk mund te shtoni me regjistrime. Eshte arritur maksimumi.\n");
        return;
    }

    printf("Shkruaj ID e nxenesit: ");
    newId = readInt();

    if (idExists(records, *count, newId)) {
        printf("Ky ID ekziston tashme. Ju lutem perdorni nje ID tjeter.\n");
        return;
    }

    records[*count].id = newId;

    printf("Shkruaj emrin e nxenesit: ");
    fgets(records[*count].studentName, sizeof(records[*count].studentName), stdin);
    records[*count].studentName[strcspn(records[*count].studentName, "\n")] = '\0';

    if (strlen(records[*count].studentName) == 0) {
        printf("Emri nuk mund te jete bosh. Regjistrimi nuk u ruajt.\n");
        return;
    }

    printf("Shkruaj progresin / rezultatin: ");
    records[*count].progress = readInt();

    if (records[*count].progress < 0 || records[*count].progress > 100) {
        printf("Rezultati duhet te jete nga 0 deri ne 100. Regjistrimi nuk u ruajt.\n");
        return;
    }

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
        displaySingleRecord(records[i], i);
    }

    printf("Gjithsej regjistrime: %d/%d\n", count, MAX_RECORDS);
}

void showReport(struct ProgressRecord records[], int count) {
    if (count == 0) {
        printf("\n===== RAPORTI ANALITIK =====\n");
        printf("Nuk ka regjistrime per analizim.\n");
        return;
    }

    int totalProgress = 0;
    int highest = records[0].progress;
    int lowest = records[0].progress;
    int advancedCount = 0;

    for (int i = 0; i < count; i++) {
        totalProgress += records[i].progress;

        if (records[i].progress > highest) {
            highest = records[i].progress;
        }

        if (records[i].progress < lowest) {
            lowest = records[i].progress;
        }

        if (records[i].status == ADVANCED) {
            advancedCount++;
        }
    }

    float average = (float) totalProgress / count;

    printf("\n===== RAPORTI ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i rasteve Advanced: %d\n", advancedCount);
    printf("Mesatarja e progresit: %.2f\n", average);
    printf("Vlera me e larte: %d\n", highest);
    printf("Vlera me e ulet: %d\n", lowest);

    printf("\nKlasifikimi:\n");

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

void searchById(struct ProgressRecord records[], int count) {
    int searchId;
    int found = 0;

    if (count == 0) {
        printf("Nuk ka regjistrime per kerkim.\n");
        return;
    }

    printf("Shkruaj ID-ne qe deshiron te kerkosh: ");
    searchId = readInt();

    printf("\n===== REZULTATI I KERKIMIT SIPAS ID-SE =====\n");
    for (int i = 0; i < count; i++) {
        if (records[i].id == searchId) {
            displaySingleRecord(records[i], i);
            found = 1;
        }
    }

    if (!found) {
        printf("Asnje regjistrim nuk u gjet me kete ID.\n");
    }
}

void searchByName(struct ProgressRecord records[], int count) {
    char searchName[50];
    int found = 0;

    if (count == 0) {
        printf("Nuk ka regjistrime per kerkim.\n");
        return;
    }

    printf("Shkruaj emrin qe deshiron te kerkosh: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strlen(searchName) == 0) {
        printf("Emri i kerkuar nuk mund te jete bosh.\n");
        return;
    }

    printf("\n===== REZULTATI I KERKIMIT SIPAS EMRIT =====\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].studentName, searchName) == 0) {
            displaySingleRecord(records[i], i);
            found = 1;
        }
    }

    if (!found) {
        printf("Asnje regjistrim nuk u gjet me kete emer.\n");
    }
}

void searchMenu(struct ProgressRecord records[], int count) {
    int choice;

    if (count == 0) {
        printf("Nuk ka regjistrime te ruajtura per kerkim.\n");
        return;
    }

    printf("\n===== MENUJA E KERKIMIT =====\n");
    printf("1. Kerko sipas ID-se\n");
    printf("2. Kerko sipas emrit\n");
    printf("Zgjedh opsionin: ");

    choice = readInt();

    switch (choice) {
        case 1:
            searchById(records, count);
            break;
        case 2:
            searchByName(records, count);
            break;
        default:
            printf("Opsion i pavlefshem ne kerkim.\n");
    }
}

int main() {
    struct ProgressRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Shfaq raportin analitik\n");
        printf("4. Kerko regjistrim\n");
        printf("5. Dil\n");
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
                searchMenu(records, count);
                break;
            case 5:
                printf("Programi po mbyllet...\n");
                break;
            default:
                printf("Opsion i pavlefshem. Ju lutem zgjidhni 1, 2, 3, 4 ose 5.\n");
        }

    } while (choice != 5);

    return 0;
}