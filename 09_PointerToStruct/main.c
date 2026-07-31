#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main(){
    struct Student student;
    struct Student *ptr = &student;

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