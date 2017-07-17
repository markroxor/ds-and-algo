#include<stdio.h>

int coinChange(int change[],int size,int n)
{
    int count[n+1];
    for(int i=0;i<=n+1;i++)
        count[i]=1;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0)
                count[i]=1;
            else if(change[j]>=i)
                continue;
            else
            count[j] += count[j-change[i]];
        } 
    }

    return count[n];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", coinChange(arr, m, n));
    return 0;
}
