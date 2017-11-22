#include <stdio.h>
#include <limits.h>
using namespace std;

int min(int a,int b)
{return a<b?a:b;}

void palinPart(char str[],int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
       dp[i][i]=1;

    for(int l=2;l<n;l++)
        for(int i=0;i+l-1<n;i++)
            {
                int j=i+l-1;
                if(str[i]==str[j])
                {
                    if(l==2)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j] = 0;

             //   printf("%d %d %d\n",i,j,dp[i][j]);
            }

    int c[n];
/*
    for(int i=0;i<n;i++)
    {

        if(dp[0][i])
            c[i] = 0;

        else
        { 
        c[i]=i;

        for(int j=1;j<=i;j++)
        {
            if(j==0 and dp[j][i])
            {
                c[i] = 0;
                break;
            }
            if(dp[j][i])
            	c[i] = min(c[i],c[j-1]+1); 
        }
        }
        printf("%d ",c[i]);
    }
 */

    for (int i=0; i<n; i++)
    {
        if (dp[0][i] == true)
            c[i] = 0;
        else
        {
            c[i] = i;
            for(int j=1;j<=i;j++)
            {
                if(dp[j][i])
                    c[i]=min(c[i],1+c[j-1]);
            }
        }
    }
    
    printf("%d\n",c[n-1]);
}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        char str[1005];
        scanf("%s",str);

        int n;
        for (n=0;str[n]!='\0';n++);
        palinPart(str,n);
    }
	return 0;
}
