#include <stdio.h>
#include <stdlib.h>

void Display(int *arr, int length)
{

    printf("Elements of the array are: {");
    for (int i = 0; i < length; i++)
    {   
        printf("%d", arr[i]);
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(){
    int n;
    printf("Enter the value of n(array size: ");
    scanf("%d", &n);
    
    int *arr;
    arr = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    Display(arr, n);
    free(arr);
    return 0;
}