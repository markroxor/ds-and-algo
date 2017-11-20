#include <stdio.h>
using namespace std;

int max(int a,int b)
{return a>b?a:b;}

void palin(char arr[])
{
    int n=0;
    for(n=0;arr[n]!='\0';n++);
    int dp[n][n];

    for(int i=0;i<n;i++)
            dp[i][i]=1;

    for(int len=1;len<=n;len++)
    {
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            if(len==1)
                dp[i][j]=1;
            else if (len==2 and arr[i]==arr[j])
                dp[i][j] = 2;
            else if (len==2)
                dp[i][j] = 1;
            else if(arr[i]==arr[j])
                dp[i][j] = dp[i+1][j-1]+2;
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
           // printf("%d %d %d %d\n",len,i,j,dp[i][j]);


        }
    }
    printf("%d\n",dp[0][n-1]);
}


int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        
        char arr[1005];
   		scanf("%s",arr);
        
		palin(arr);
    }
	return 0;
}
