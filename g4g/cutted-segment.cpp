#include <stdio.h>
using namespace std;

int max(int x,int y)
{return x>y?x:y;}

int cutRod(int arr[],int sum)
{
    int dp[sum+1];

    for(int i=0;i<=sum;i++)
        dp[i]=-1;

    for(int s=1;s<=sum;s++)
    {
        for(int i=0;i<3;i++)
        {
            if(s==arr[i])
                dp[s] = max(dp[s],1);
            else if(s>arr[i] and dp[s-arr[i]]!=-1)
            {
                dp[s] = max(dp[s],dp[s-arr[i]]+1);
            }
            //printf("%d %d %d\n",s,dp[s],arr[i]);
        }
    }

    return dp[sum];
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

        int arr[3];
        for(int i=0;i<3;i++)
            scanf("%d",&arr[i]);

        printf("%d\n",cutRod(arr,n));
    }
	return 0;
}
