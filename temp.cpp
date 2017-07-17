// C++ program to sizes of data types
#include<iostream>
#include<stdio.h>
using namespace std;

bool isSubsetSum(int set[],int n,int sum)
{
    int dp[sum+1][n+1];
    for(int s=0;s<=sum;s++)
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                dp[s][i] = 0;
            else if (s==0)
                dp[s][i] = 1;
            else if(s>=set[i-1])
                dp[s][i] = max(dp[s][i-1],dp[s-set[i-1]][i-1]);
        }

    for(int i=0;i<=n;i++)
        printf("%d ",dp[sum][i])
    return dp[sum][n];
}

int main()
{
    int set[] = {3, 5, 10};
    int sum = 20;
    int n = sizeof(set)/sizeof(set[0]);
    printf("%d\n",isSubsetSum(set,n,sum));
    return 0;
}
