#include<stdio.h>
#include<cstring>

int max(int i,int j)
{return i>j?i:j;}

int lcs(char X[], char Y[], int m,int n)
{
    int LCS[m][n];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0)
                LCS[i][j] = 0;
            else if(X[i-1]==Y[j-1])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
        }


    int i=m,j=n;
    while(i and j)
        {
            if(LCS[i][j]==LCS[i-1][j-1]+1)
            {
                printf("%c",X[i-1]);
                i--;j--;
            }
            else
            {
                if(LCS[i-1][j]>LCS[i][j-1])
                    i--;
                else
                    j--;
            }
        }

    return LCS[m][n];

}

/* Driver program to test above function */
int main()
{
    char X1[] = "AGGTAB";
    char Y1[] = "GXTXAYB";
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    printf("\nLength of LCS is %d\n", lcs( X, Y, m, n ) );

    return 0;
}
