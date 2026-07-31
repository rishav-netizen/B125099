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
    int highest_marks = 0, highest_marks_index, total = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for five students:\n");
        printf("Enter the student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the student %d roll: ", i + 1);
        scanf("%d", &students[i].roll);
        printf("Enter the student %d marks: ", i + 1);
        scanf("%d", &students[i].marks);
        total += students[i].marks;
        if (highest_marks < students[i].marks)
        {
            highest_marks = students[i].marks;
            highest_marks_index = i;
        }

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
    

    printf("The highest marks is %d scored by student: %s", highest_marks, students[highest_marks_index].name);
    printf("The average is %f", (float)total/n);
    return 0;
}

void print_data(Student student)
{
    // the positive padding gives right alignment hence I use -ve
    printf("| %-20s | %-8d | %-10d |\n", student.name, student.roll, student.marks);
}