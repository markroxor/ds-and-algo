#include<stdio.h>
#include<limits.h>
int max(int a,int b)
{return a>b?a:b;}

int cutRod(int rod[], int size)
{
    int profit[size+1];
    profit[0] = 0;

    for(int l=1;l<=size;l++)
    {
        int length = l;
        profit[l] = rod[l-1];

        for(int i=1;i<=l;i++)
        {
            profit[l] = max(rod[i-1]+profit[l-i],profit[l]);
        }
    }

    return profit[size];
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    return 0;
}
