#include<stdio.h>
#include<stdlib.h>
//  finding the max number in the array..
int getMax(int arr[],int n){
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
//  counting sort..
/*  count array is used to store the count of occurrences of each digit at the specified place.
The first loop counts the occurrences of each digit in the count array.
The second loop modifies the count array to store cumulative counts.
The third loop builds the output array by placing elements in their sorted order.
The last loop updates the original array with the sorted values.
*/
void count_sort(int arr[],int n,int exp){
    int output[n];
    int count[10]={0}; 
    int i;
    for(i=0; i<n; i++)
        count[(arr[i]/exp)%10]++; // storing count of occurence in the count array.
    for(i=1;i<10;i++)
        count[i]+=count[i-1]; 
    for(i=n-1;i>=0;i--){   // building the output array.
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) // storing the output value in arr so that it contains sorted elements.
        arr[i] = output[i];
}
// radix-sort function..
/*  It finds the maximum number in the array using the getMax function.
The outer loop runs for each digit place (units, tens, hundreds, etc.) in the numbers.
It calls the countSort function for each digit place.
*/
void radix_sort(int arr[],int n){
    int m = getMax(arr,n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}
// driver function
int main(){
    int n;
    printf("enter value of n: ");
    scanf("%d",&n);
    int arr[n],i;
    printf("enter value of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nmax element: %d\n",getMax(arr,n));
    radix_sort(arr,n);
    for(i=0;i<n;i++){
        printf("  %d  ",arr[i]);
    }    
    return 0;
}