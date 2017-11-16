#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int comp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}

int abs(int a)
{return a<0?-a:a;}

int count( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
    int table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

int msp(int arr[],int n, int sum)
{
    int dp[sum+1][n];
     
    for(int s=0;s<=sum;s++)
        for(int i=0;i<n;i++)
        {
            dp[s][i]=0;
            if(s==0)
            {dp[s][i]=1;continue;}
    
            if(i>0)
           dp[s][i] += dp[s][i-1];// true;
    
            if(s>=arr[i])
           dp[s][i] += dp[s-arr[i]][i];
        }
    return dp[sum][n-1];
}

int msp1(int arr[],int n, int sum)
{
    int dp[sum+1];
    
    memset(dp,0,sizeof(dp));
    dp[0]=1;

    for(int s=0;s<=sum;s++)
        for(int i=0;i<n;i++)
        {
            if(s>=arr[i])
            dp[s]+=dp[s-arr[i]];
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
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int sum;
        scanf("%d",&sum);

        printf("%d\n",msp1(arr,n,sum));
    }
	return 0;
}
