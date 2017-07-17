#include<stdio.h>
#include<limits.h>
#define V 5

int minKeyIndex(int key[],int visited[])
{
    int ind=-1,mini=INT_MAX;
    for(int v=0;v<V;v++)
    {
        if(not visited[v] and key[v]<mini)
            ind=v,mini = key[v];
    }

    return ind;
}

void primMST(int graph[V][V])
{
    int visited[V],key[V],par[V];
    for (int i=0;i<V;i++)
        visited[i] = 0,key[i]=INT_MAX;

    key[0]=0;
    visited[0]=1;
    par[0]=-1;

    int count=V,minInd=0;
    while(V>=0 and --count)
    {

        for(int i=0;i<V;i++)
        {
            if(not visited[i] and graph[minInd][i] and key[i]>graph[minInd][i])
                key[i]=graph[minInd][i],par[i]=minInd;
        }

        minInd = minKeyIndex(key,visited);
        visited[minInd] = 1;

    }
    for(int i=0;i<V;i++)
    {
        printf("%d %d         wt=%d\n",i,par[i],graph[i][par[i]]);
    }
}

// driver program to test above function
int main()
{
       /* Let us create the following graph
                    2    3
    (0)--(1)--(2)
    |   / \   |
    6| 8/   \5 |7
    | /     \ |
    (3)-------(4)
    9          */
    int graph[V][V] = {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0},
                        };

    // Print the solution
    primMST(graph);

    return 0;
}
