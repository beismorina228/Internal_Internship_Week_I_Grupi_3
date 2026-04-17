#include <stdio.h>

#define MAX_STUDENTS 5

enum Status
{
    IN_PROGRESS = 1,
    COMPLETED = 2,
    FAILED = 3
};

struct Student
{
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void showStudents(struct Student students[], int count)
{
    if(count == 0)
    {
        printf("\nNo records available.\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        switch(students[i].status)
        {
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
            case FAILED:
                printf("Status: Failed\n");
                break;
            default:
                printf("Status: Unknown\n");
        }
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int statusChoice;

    do
    {
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(count < MAX_STUDENTS)
                {
                    printf("Enter ID: ");
                    scanf("%d", &students[count].id);

                    printf("Enter Name: ");
                    scanf("%s", students[count].name);

                    printf("Enter Progress: ");
                    scanf("%f", &students[count].progress);

                    printf("\nChoose Status:\n");
                    printf("1. In Progress\n");
                    printf("2. Completed\n");
                    printf("3. Failed\n");
                    printf("Choice: ");
                    scanf("%d", &statusChoice);

                    switch(statusChoice)
                    {
                        case 1:
                            students[count].status = IN_PROGRESS;
                            break;
                        case 2:
                            students[count].status = COMPLETED;
                            break;
                        case 3:
                            students[count].status = FAILED;
                            break;
                        default:
                            printf("Invalid status! Record not added.\n");
                            continue;
                    }

                    count++;
                    printf("Student added successfully!\n");
                }
                else
                {
                    printf("Maximum limit reached!\n");
                }
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid menu option!\n");
        }

    } while(choice != 3);

    return 0;
}