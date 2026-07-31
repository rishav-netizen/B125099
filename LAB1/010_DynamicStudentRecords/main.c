#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int roll;
    char name[50];
    float marks;
} Student;

int main()
{
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students;
    students = malloc(n * sizeof(Student));

    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll: ");
        scanf("%d", &students[i].roll);

        printf("Name: ");
        scanf(" %49[^\n]", students[i].name); 
        // %s cant take spaces so I did this and the 49 for length limit

        printf("Marks: ");
        scanf("%f", &students[i].marks);


    }

    int highest_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (students[i].marks > students[highest_index].marks)
        {
            highest_index = i;
        }
    }

    printf("\nStudent with highest marks:\n");
    printf("Roll Number: %d\n", students[highest_index].roll);
    printf("Name: %s\n", students[highest_index].name);
    printf("Marks: %.2f\n", students[highest_index].marks);

    free(students);

    return 0;
}