#include<stdio.h>
#include<limits.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int min(int a,int b)
{
    return a<b?a:b;
}

int eggDrop(int eggs,int floors)
{
    int dp[eggs+1][floors+1];
    for(int i=1;i<=eggs;i++)
        dp[i][0]=0,dp[i][1]=1;

    for(int j=1;j<=floors;j++)
        dp[1][j] = j;

    for(int i=2;i<=eggs;i++)
        for(int j=2;j<=floors;j++)
        {
            dp[i][j] = INT_MAX;
            for(int k=1;k<=j;k++)
            {
                /*
                if(i==1)
                    dp[i][j] = j;
                else if (j==0)
                    dp[i][j] = 0;
                else if (j==1)
                    dp[i][j] = 1;
                else*/
                    dp[i][j] = min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
            }
        }

    return dp[eggs][floors];
}

int main()
{
    int n = 2, k = 36;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
    "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}
