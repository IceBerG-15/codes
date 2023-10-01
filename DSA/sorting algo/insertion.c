//in this sorting method, we take i+1th element as key element, then check if its left side element are smaller than key element.
//if not then we go to j-loop, where we copy jth element to j+1th element, then decrement and check again.
//at last at the unsorted first element is swapped with key element.

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[],int n);

int main()
{
    int n;
    printf("\n enter size: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        printf("\n enter element: ");
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
}

void insertion_sort(int a[],int n)
{
    int temp;
    int key;
    int j;
    for(int i=1;i<n;i++)
    {   
        key=a[i];
        j=i-1;
        while (key < a[j] && j >= 0) 
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
        printf("\nelement after %d pass.",i);
        for(int k=0;k<n;k++)
            printf("%d ",a[k]);
        
    }
}