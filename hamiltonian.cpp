#include <stdio.h>

bool hamCycleUtil(bool *graph,int *par,int covered,int src,int V)
{
    if(covered==V)
    {
        if(graph[V*src])
        {
            par[0]=src;
            return true;
        }
        return false;
    }

    for(int i=0;i<V;i++)
    {
        if(graph[src*V+i]==0 or par[i]!=-1)
            continue;

        par[i] = src;
        if(hamCycleUtil(graph,par,covered+1,i,V))
            return true;

        par[i] = -1;
    }

    return false;
}

void hamCycle(bool *graph,int V)
{
    int par[V];
    for(int i=0;i<V;i++)
        par[i] = -1;

    
    par[0]=0;
    
    if(hamCycleUtil(graph,par,1,0,V))
    {
        int p =par[0];
    
        printf("0-");
        while(p)
        {
            printf("%d-",p);
            p = par[p];
        }
    }
    //    printSolution(par);

}

void printGraph(bool *graph,int V)
{
    for(int i=0;i<V;i++)
    {
        printf("%d - ",i);
        for(int j=0;j<V;j++)
            printf("%d ",graph[i*V+j]);

        printf("\n");
    }
}
// driver program to test above function
int main()
{
    /* Let us create the following graph
    (0)--(1)--(2)
    |   / \   |
    |  /   \  |
    | /     \ |
    (3)-------(4)    */
    int V=5;
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0},
                        };

    // Print the solution

    /* Let us create the following graph
    (0)--(1)--(2)
    |   / \   |
    |  /   \  |
    | /     \ |
    (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                    };

    // Print the solution
    bool graph3[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            graph3[i][j] = 0;

    int arr[28]={2, 1, 10, 2, 6, 3, 5, 4, 10, 5, 10, 6, 6, 7, 6, 8, 10, 9, 4, 9, 3, 8, 3, 7, 5, 9, 6, 5};
    for(int i=0;i<14;i++)
        graph3[arr[2*i+1]-1][arr[2*i]-1] = 1,graph3[arr[2*i]-1][arr[2*i+1]-1] = 1;
    
    V = 10;
    printGraph((bool *)graph3,V);
    hamCycle((bool *)graph3,V);

    return 0;
}
