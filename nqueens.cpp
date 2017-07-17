#include <stdio.h>
#define n 4

int abs(int n)
{
    return n>0?n:-n;
}

bool isSafe(int grid[n][n],int cur)
{
    for(int i=0;i<n;i++)
        if(grid[i][cur%n])
            return false;

    for(int j=0;j<n;j++)
        if(grid[cur/N][j])
            return false;

    for(int i=0;i<)
}

bool nqueensUtil(grid,cur)
{

}

void nqueens()
{
   int grid[n][n];
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         grid[i][j] = 0;

    if(nqueensUtil(grid,cur))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                printf("%d ",grid[i][j]);
        printf("\n");
        return;
    }

    printf("NOSO!\n");

}

int main()
{
    nqueens();
    return 0;
}
