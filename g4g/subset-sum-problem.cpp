#include <stdio.h>
using namespace std;

void subsum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum&1)
    {
        printf("NO\n");
        return;
    }

    int dp[sum][n];
    for(int s=0;s<=sum/2;s++)
    {
        for(int i=0;i<=n;i++)
        {
            if(s==0)
                dp[s][i] = 1;
            else if(i==0)
                dp[s][i] = 0;
            else if(s>=arr[i-1])
                dp[s][i] = dp[s-arr[i-1]][i-1];
            else
                dp[s][i] = dp[s][i-1];
        }
    }

    if(dp[sum/2][n])
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        subsum(arr,n);
    }
    return 0;
}
