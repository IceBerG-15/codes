#include <stdio.h>
#include <stdlib.h>

void binary_search(int a[],int n);

int main()
{
    int n;
    printf("\n enter size: ");
    scanf("%d",&n);
    int a[n];
    printf("\n enter element in sorted order...");
    for(int i=0; i<n; i++)
    {
        printf("\n enter element: ");
        scanf("%d",&a[i]);
    }
    binary_search(a,n);
}

void binary_search(int a[],int n)
{
    int x;
    printf("\n enter element you want to search: ");
    scanf("%d",&x);
    int mid;
    int low=0;
    int high=n-1;
    int k=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            k=mid+1;
            break;
        }
        else if(x>a[mid])
            low=mid+1;
        else if(x<a[mid])
            high=mid-1;
    }
    if(k==0)
        printf("\n element not found!!!");
    else
        printf("\n element found at %d position",k);
}