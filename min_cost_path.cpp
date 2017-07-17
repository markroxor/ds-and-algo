#include<stdio.h>

int min(int i,int j)
{
    return i<j?i:j;
}

int minCost(int *arr,int r,int c)
{
    int cost[r][c];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            {
                if(i==0 and j==0)
                    cost[i][j] = *((arr+i*c)+j);
                else if(i==0)
                    cost[i][j] = *((arr+i*c)+j) + cost[i][j-1];
                else if(j==0)
                    cost[i][j] = *((arr+i*c)+j) + cost[i-1][j];
                else    
                    cost[i][j] = *((arr+i*c)+j) + min(cost[i-1][j],cost[i-1][j-1]);
            //printf("%d\n",cost[i][j]);
            }

    return cost[r-1][c-1];
}

int main()
{
    int R=3,C = 3;
    int cost[R][C] = { {1, 2, 3},
    {4, 8, 2},
    {1, 5, 3} };
    printf(" %d ", minCost(*cost, R, C));
    return 0;
}
