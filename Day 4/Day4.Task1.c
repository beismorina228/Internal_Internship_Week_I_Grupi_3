#include <stdio.h>

#define MAX_STUDENTS 5

enum Status
{
    IN_PROGRESS,
    COMPLETED
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
        printf("No students added yet.\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        if(students[i].status == COMPLETED)
            printf("Status: Completed\n");
        else
            printf("Status: In Progress\n");
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("Choose: ");
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

                    if(students[count].progress >= 50)
                        students[count].status = COMPLETED;
                    else
                        students[count].status = IN_PROGRESS;

                    count++;
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
                printf("Invalid option!\n");
        }

    } while(choice != 3);

    return 0;
}
