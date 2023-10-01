#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("enter size of array: ");
    scanf("%d", &size);
    int array[size];
    for(int i=0;i<size;i++)
    {
        printf("enter number: ");
        scanf("%d", &array[i]);
    }
    printf("array elements are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
    return 0;
}
