#include <stdio.h>
#include <stdlib.h>

void linear_search(int a[],int n);

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
    linear_search(a,n);
}

void linear_search(int a[],int n)
{
    int x;
    printf("\n enter element you want to search: ");
    scanf("%d",&x);
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==x)
        {
            k=i+1;
            break;
        }
    }
    for(int i=0; i<n; i++)
        printf("\t%d",a[i]);
    if(k==0)
        printf("\n element not found!!!!");
    else
        printf("\n element found at %d..",k);
}