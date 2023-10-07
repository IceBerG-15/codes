#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    int workload[n];
    printf("enter workload: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", & workload[i]);
    }
    int rating=0,rat[n],rat_count=0;
    int j;
    for(int i=0; i<n-1; i++)
    {
        if(workload[i]>6)
        {
            j=i;
            while(workload[j]>6 && j<n)
            {
                rat[rat_count++]=workload[j];
                j++;
            }
            if(rating<rat_count)
            {
                rating=rat_count;
                for(j=0;j<rat_count; j++)
                    printf(" %d ", rat[j]);
                printf("\n");
            }       
            rat_count=0;
        }
    }
    printf("rating: %d",rating);
}