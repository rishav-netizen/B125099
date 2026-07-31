#include <stdio.h>

typedef struct Student
{
    int roll;
    char name[40];
    int marks;

}Student;

void print_data(Student student);

int main(){
    int n = 5;
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for five students:\n");
        printf("Enter the student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the student %d roll: ", i + 1);
        scanf("%d", &students[i].roll);
        printf("Enter the student %d marks: ", i + 1);
        scanf("%d", &students[i].marks);
        printf("");
    }

    printf("The data entered by you for each student is as follows:\n");
    printf("+----------------------------------------------+\n");
    printf("| %-20s | %-8s | %-10s |\n", "Name", "Roll", "Marks");
    printf("+----------------------------------------------+\n");
    for (int i = 0; i < n; i++)
    {
        print_data(students[i]);
    }
    printf("+----------------------------------------------+\n");
    
    return 0;
}

void print_data(Student student)
{
    // the positive padding gives right alignment hence I use -ve
    printf("| %-20s | %-8d | %-10d |\n", student.name, student.roll, student.marks);
}