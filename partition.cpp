#include<stdio.h>

bool findPartition(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum&1)
        return false;

    bool dp[sum+1][n+1];
    for(int s=0;s<=sum/2;s++)
    {
        dp[s][0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                dp[s][i] = true;
            else if(s<i)
                dp[s][i] = dp[s][i-1];
            else
                dp[s][i] = dp[s][i-1] or dp[s-arr[i-1]][i-1];

        }
    }


    return dp[sum/2][n+1];
}

int main()
{
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (findPartition(arr, n) == true)
        printf("Can be divided into two subsets of equal sum");
    else
    printf("Can not be divided into two subsets of equal sum");
    return 0;
}
