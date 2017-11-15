#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int comp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}

int abs(int a)
{return a<0?-a:a;}

int msp(int arr[],int n, int sum)
{
/*    if(n<2)
        return arr[0];
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
*/
    int dp[sum+1][n];

    for(int s=0;s<=sum;s++)
        for(int i=0;i<n;i++)
        {
            if(s==0)
                dp[s][i]=1;/*
            else if (i==0)
                dp[s][i]=0;*/
            else if(s>=arr[i])
                dp[s][i] = dp[s][i-1] + dp[s-arr[i]][i-1];// true;
            else
                dp[s][i] = dp[s][i-1];
        }
/*
    for(int i=sum/2;i>=0;i--)
        if(dp[i][n])
            return abs(sum-2*i);
*/
    return dp[sum][n-1];
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
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int sum;
        scanf("%d",&sum);

        printf("%d\n",msp(arr,n,sum));
    }
	return 0;
}
