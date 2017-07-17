#include<stdio.h>
#define N 4


bool solving(int maze[N][N], int par[N*N],int cur)
{
    if(cur==N*N-1)
        return true;
    if(cur>=N*N)
        return false;

    if(not maze[cur/N][cur%N])
        return false;
    
    if((cur+N)<N*N)
    {
        par[cur+N]=cur;
        if(solving(maze,par,cur+N))
        {
            printf("%d %d %d is true\n",cur+N,(cur+N)/N,(cur+N)%N);
            return true;
        }
        par[cur+N]=-1;

    }
    if((cur+1)%N)
    {
        par[cur+1]=cur;
        if(solving(maze,par,cur+1))
        {
            printf("%d %d %d is true\n",cur+1,(cur+1)/N,(cur+1)%N);
            return true;
        }
        par[cur+1]=-1;
    }

    return false;
}

void solveMaze(int maze[N][N])
{
    int par[N*N];
    for(int i=0;i<N*N;i++)
        par[i] = -1;

    par[0]=0;
    if(solving(maze,par,0))
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                maze[i][j] = 0;

        int p = par[N*N-1];
        while(p)
        {
            maze[p/N][p%N] = 1;
            p = par[p];
        }
        maze[0][0] = 1;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                printf("%d ",maze[i][j]);

            printf("\n");
        }
    }
    else
        printf("No Solution\n");
}


// driver program to test above function
int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
                         {1, 1, 0, 1},
                         {0, 1, 0, 0},
                         {1, 1, 1, 1}
                         };

solveMaze(maze);
return 0;
}
