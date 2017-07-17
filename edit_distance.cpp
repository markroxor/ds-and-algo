#include<stdio.h>
#include<string.h>
using namespace std;

int min(int a,int b)
{
    return a>b?b:a;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int editDist(char *st1,char *st2, int m,int n)
{
    int dist[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dist[i][j] = j;
            else if(j==0)
                dist[i][j] = i;
            else if (st1[i-1]==st2[j-1])
                dist[i][j] = dist[i-1][j-1];
            else
                dist[i][j] = 1+min(min(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1]);
        }

    return dist[m][n];
}


int main()
{
    // your code goes here
    char str1[] = "sunday";
    char str2[] = "saturday";
    
    printf("%d\n", editDist( str1 , str2 , strlen(str1), strlen(str2)));
    
    return 0;
                          
}
