#include <stdio.h>
#include <string.h>

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

void updateProgress(float *progress)
{
    *progress += 5;
}

void showStudents(struct Student students[], int count)
{
    int i;

    for(i = 0; i < count; i++)
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
        printf("\n-Student Progress Tracker -\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
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

                    updateProgress(&students[count].progress);

                    count++;

                    printf("Student added successfully!\n");
                }
                else
                {
                    printf("List is full!\n");
                }
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}
