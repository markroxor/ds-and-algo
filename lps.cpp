#include<stdio.h>
#include<cstring>

int max(int a,int b)
{return a>b?a:b;}

int lps(char seq[])
{
    int n =strlen(seq);
    int dp[n+1][n+1];

    for(int l=1;l<=n;l++)
    {
        for(int st=0;st+l-1<n;st++)
        {
            int ed = st+l-1;
            if(st==ed)
                dp[st][ed] = 1;

            else if(seq[st]==seq[ed])
                dp[st][ed] = dp[st+1][ed-1]+2;

            else
                dp[st][ed] = max(dp[st][ed-1],dp[st+1][ed]);
        }
    }

    int st=0,ed=n-1;
    char palin[dp[0][n-1]];
    int i=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }

    return dp[0][n-1];
    while(ed-st>=0)
    {
        printf("%d %d\n",st,ed);
        if(dp[st][ed] == dp[st+1][ed-1]+2)
        {
            palin[i++]=seq[st];
            printf("%d %c\n",st,seq[st]);
            //palin[ed]=seq[st];
            st++;ed--;
        }
        else if(dp[st][ed-1]==dp[st][ed])
        {
            ed--;
        }
        else
            st++;
    }
    return dp[0][n-1];
}

//BABCBAB

int main()
{
    char seq[] = "BBABCBCAB";//"GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq));
    return 0;
}
