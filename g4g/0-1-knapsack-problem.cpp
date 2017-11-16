#include <stdio.h>
using namespace std;

int knap(int val[],int wt[],int n,int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++)
        {
            if(w==0 or i==0)
                dp[i][w]=0;
            else if(w>=wt[i-1] and dp[i-1][w-wt[i-1]]+val[i-1]>dp[i-1][w])
                dp[i][w] = dp[i-1][w-wt[i-1]]+val[i-1];
            else
                dp[i][w] = dp[i-1][w];
        }

    return dp[n][W];
}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int W;
        scanf("%d",&W);
        
        int val[n],wt[n];
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        
        for(int i=0;i<n;i++)
            scanf("%d",&wt[i]);

        printf("%d\n",knap(val, wt, n, W));
    }
	return 0;
}
