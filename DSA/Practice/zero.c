//shifting all zeros in the array to last position,without changing the order of other elements

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("\n enter size: ");
    scanf("%d", &size);     //size of array
    int array[size];        //intialising array with size
    for(int i=0; i<size; i++)       //loop to take element input from user
    {
        printf("\n enter number: ");
        scanf("%d", &array[i]);
    }
    int p=size;  //storing value of size in this so the value in size doesnt get decremented, else we'll not be able to print array and do shifting
    for(int i=0; i<p; i++)
    {
        if(array[i]==0)
        {
            for(int k=i; k<size-1; k++) //in this loop we are shifting positions of elements to front one by one
                array[k]=array[k+1];
            array[size-1]=0;            //then intialising last position of array with 0
            i--;                        // decrementing i so that we don't skip that newly positioned element
            p--;                        //decrementing array size cause we dont want it to check replaced elements again
        }
    }
    printf("\n array elements: ");
    for(int i=0; i<size;i++)
        printf("  %d", array[i]);
    return 0;
}