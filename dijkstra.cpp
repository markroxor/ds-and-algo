#include <stdio.h>
#include<limits.h>
#define V 9

int minKeyIndex(int distance[],int visited[])
{
    int ind=-1,mini=INT_MAX;
    for(int v=0;v<V;v++)
    {
        if(not visited[v] and distance[v]<mini)
            ind=v,mini = distance[v];
    }

    return ind;
}

void dijkstra(int graph[V][V],int src)
{
    int visited[V],distance[V],par[V];
    for (int i=0;i<V;i++)
        visited[i] = 0,distance[i]=INT_MAX;

    distance[src]=src;
    visited[src]=1;
    par[src]=-1;

    int count=V,minInd=src;
    while(V>=0 and --count)
    {

        for(int i=0;i<V;i++)
        {
            if(not visited[i] and graph[minInd][i] and distance[i]>distance[minInd]+graph[minInd][i])
                distance[i]=graph[minInd][i]+distance[minInd],par[i]=minInd;
        }

        minInd = minKeyIndex(distance,visited);
        visited[minInd] = 1;

    }

    for(int i=0;i<V;i++)
        printf("%d        wt=%d\n",i,distance[i]);
}


int main()
{
/* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
                        };

    dijkstra(graph, 0);

    return 0;
}
