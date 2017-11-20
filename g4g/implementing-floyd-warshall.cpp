#include <stdio.h>
using namespace std;

int min(int a,int b)
{return a<b?a:b;}

void fw(int *arr,int n)
{
    int dp[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            dp[i][j]=*(arr+i*n+j);
//            printf("%d ",*(arr+i*n+j));
        }

            for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%d ",dp[i][j]);

    return;
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
        
        int *arr;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",arr+i*n+j);
        
        fw(arr,n);
        printf("\n");
    }
	return 0;
}
