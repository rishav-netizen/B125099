#include <stdio.h>

typedef struct Student
{
    int roll;
    char name[50];
    float marks;
}Student;

int main(){
    Student student;
    Student *ptr = &student;

    printf("Enter roll number: ");
    scanf("%d", &ptr->roll);

    printf("Enter name: ");
    scanf(" %49[^\n]", ptr->name);

    printf("Enter marks: ");
    scanf("%f", &ptr->marks);

    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", ptr->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}