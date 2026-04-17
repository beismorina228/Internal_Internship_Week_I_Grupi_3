#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50
#define INPUT_SIZE 100

enum Status
{
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
};

struct Student
{
    int id;
    char name[NAME_LENGTH];
    float progress;
    enum Status status;
};

void trimNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}

int readIntValue(const char *prompt, int *value)
{
    char buffer[INPUT_SIZE];
    char extra;

    printf("%s", prompt);
    if(fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 0;
    }

    return sscanf(buffer, " %d %c", value, &extra) == 1;
}

int readIntInRange(const char *prompt, int min, int max)
{
    int value;

    while(1)
    {
        if(!readIntValue(prompt, &value))
        {
            printf("Ju lutem shkruani nje numer te vlefshem.\n");
            continue;
        }

        if(value < min || value > max)
        {
            printf("Vlera duhet te jete mes %d dhe %d.\n", min, max);
            continue;
        }

        return value;
    }
}

float readFloatInRange(const char *prompt, float min, float max)
{
    char buffer[INPUT_SIZE];
    char extra;
    float value;

    while(1)
    {
        printf("%s", prompt);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            continue;
        }

        if(sscanf(buffer, " %f %c", &value, &extra) != 1)
        {
            printf("Ju lutem shkruani nje vlere numerike te vlefshme.\n");
            continue;
        }

        if(value < min || value > max)
        {
            printf("Progresi duhet te jete nga %.0f deri ne %.0f.\n", min, max);
            continue;
        }

        return value;
    }
}

void readText(const char *prompt, char text[], int size)
{
    while(1)
    {
        printf("%s", prompt);
        if(fgets(text, size, stdin) == NULL)
        {
            continue;
        }

        trimNewline(text);

        if(strlen(text) == 0)
        {
            printf("Teksti nuk mund te jete bosh.\n");
            continue;
        }

        return;
    }
}

void normalizeProgress(float *progress)
{
    if(*progress < 0)
    {
        *progress = 0;
    }
    else if(*progress > 100)
    {
        *progress = 100;
    }
}

const char *statusToText(enum Status status)
{
    switch(status)
    {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

void setStatusFromChoice(enum Status *status, int choice)
{
    switch(choice)
    {
        case NOT_STARTED:
            *status = NOT_STARTED;
            break;
        case IN_PROGRESS:
            *status = IN_PROGRESS;
            break;
        case COMPLETED:
            *status = COMPLETED;
            break;
        default:
            *status = NOT_STARTED;
    }
}

void addStudent(struct Student students[], int *count)
{
    int statusChoice;
    struct Student *current;

    if(*count >= MAX_STUDENTS)
    {
        printf("Nuk mund te shtohen me shume regjistrime. Kapaciteti maksimal eshte %d.\n", MAX_STUDENTS);
        return;
    }

    current = &students[*count];

    current->id = readIntInRange("Shkruani ID (1 - 99999): ", 1, 99999);
    readText("Shkruani emrin: ", current->name, NAME_LENGTH);
    current->progress = readFloatInRange("Shkruani progresin (0 - 100): ", 0.0f, 100.0f);
    normalizeProgress(&current->progress);

    printf("\nZgjidhni statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    statusChoice = readIntInRange("Statusi: ", 1, 3);
    setStatusFromChoice(&current->status, statusChoice);

    (*count)++;
    printf("Regjistrimi u shtua me sukses.\n");
}

void showStudents(const struct Student students[], int count)
{
    int i;

    if(count == 0)
    {
        printf("Nuk ka ende regjistrime.\n");
        return;
    }

    printf("\n--- Regjistrimet e ruajtura ---\n");
    for(i = 0; i < count; i++)
    {
        printf("%d. ID: %d | Emri: %s | Progresi: %.2f | Statusi: %s\n",
               i + 1,
               students[i].id,
               students[i].name,
               students[i].progress,
               statusToText(students[i].status));
    }
}

void printReport(const struct Student students[], int count)
{
    int i;
    int completedCount = 0;
    int inProgressCount = 0;
    int notStartedCount = 0;
    float totalProgress = 0;
    float highestProgress;
    float lowestProgress;
    float averageProgress;

    if(count == 0)
    {
        printf("\nRaporti nuk mund te gjenerohet sepse lista eshte bosh.\n");
        return;
    }

    highestProgress = students[0].progress;
    lowestProgress = students[0].progress;

    for(i = 0; i < count; i++)
    {
        totalProgress += students[i].progress;

        if(students[i].progress > highestProgress)
        {
            highestProgress = students[i].progress;
        }

        if(students[i].progress < lowestProgress)
        {
            lowestProgress = students[i].progress;
        }

        if(students[i].status == COMPLETED)
        {
            completedCount++;
        }
        else if(students[i].status == IN_PROGRESS)
        {
            inProgressCount++;
        }
        else
        {
            notStartedCount++;
        }
    }

    averageProgress = totalProgress / count;

    printf("\n- Raport Analitik -\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Te perfunduara: %d\n", completedCount);
    printf("Ne progres: %d\n", inProgressCount);
    printf("Pa nisur: %d\n", notStartedCount);
    printf("Mesatarja e progresit: %.2f\n", averageProgress);
    printf("Progresi me i larte: %.2f\n", highestProgress);
    printf("Progresi me i ulet: %.2f\n", lowestProgress);

    if(averageProgress >= 85)
    {
        printf("Vleresim: Performanca e pergjithshme eshte shume e mire.\n");
    }
    else if(averageProgress >= 60)
    {
        printf("Vleresim: Performanca eshte e mire, por ka hapesire per permisim.\n");
    }
    else
    {
        printf("Vleresim: Progresi ka nevoje per me shume vemendje.\n");
    }

    if(completedCount == count)
    {
        printf("Mesazh: Te gjitha regjistrimet jane te perfunduara.\n");
    }
    else if(completedCount == 0)
    {
        printf("Mesazh: Ende nuk ka asnje regjistrim te perfunduar.\n");
    }
    else
    {
        printf("Mesazh: Ka progres, por jo te gjitha regjistrimet kane perfunduar.\n");
    }
}

int main(void)
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Task 3: Student Progress Tracker ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Shfaq raportin analitik\n");
        printf("4. Dil\n");
        choice = readIntInRange("Zgjedhja: ", 1, 4);

        switch(choice)
        {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                printReport(students, count);
                break;

            case 4:
                printf("Programi po mbyllet.\n");
                break;
        }
    }
    while(choice != 4);

    return 0;
}
