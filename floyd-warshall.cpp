#include<stdio.h>
#include<limits.h>
#include<cmath>
#define V 4
#define INF 9999

void printSolution(int dist[V][V]);

void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
                dist[i][j] = graph[i][j];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            for(int k=0;k<V;k++)
                if(dist[i][k]>dist[i][j]+dist[j][k])
                    dist[i][k] = dist[i][j]+dist[j][k];

    printSolution(dist);

}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
    " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            printf("%7s", "INF");
            else
            printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
    10
    (0)------->(3)
    |         /|\
    5 |          |
    |          | 1
    \|/         |
    (1)------->(2)
    3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                        };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
