#include<stdio.h>


void printGrid(int gird[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            printf("%d ",gird[i][j]);
        printf("\n");
    }
}

bool isSafe(int grid[9][9],int ci,int cj,int val)
{
    int bi=ci/3, bj=cj/3;

   //check row
    for(int i=0;i<9;i++)
        if(grid[ci][i]==val)
            return false;
    //check column
    for(int i=0;i<9;i++)
        if(grid[i][cj]==val)
            return false;
    //check box
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(grid[3*bi+i][3*bj+j]==val)
            return false;
    return true;
}

bool SolveSudoku(int grid[9][9])
{
    bool flag=0;
    int ci,cj;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
                ci=i;
                cj=j;
                flag=1;
            }
        }

    if(!flag)
        return true;

    for(int i=1;i<=9;i++)
    {
        bool safe = isSafe(grid,ci,cj,i);
        if(safe)
        {
            grid[ci][cj] = i;
            
            if(SolveSudoku(grid))
                return true;

            grid[ci][cj] = 0;
        }

    }

    return false;
}

int main()
{
        // 0 means unassigned cells
    
    int grid[9][9] =   {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
   if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}
