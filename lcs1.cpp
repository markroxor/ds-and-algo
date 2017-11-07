#include<stdio.h>

int lcs(char *st1, char *st2, int n1,int n2)
{
    int LCS[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
        for(int j=0;j<=n2;j++)
            LCS[i][j] = 0;
    
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
        {
            if(st1[i-1]==st2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
                LCS[i][j] = LCS[i-1][j]>LCS[i][j-1]?LCS[i-1][j]:LCS[i][j-1];
        }
    return LCS[n1][n2];
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        char st1[105],st2[105];
        scanf("%s",st1);
        scanf("%s",st2);

        printf("%d\n",lcs(st1,st2,n1,n2));
    }
}
