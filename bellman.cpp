#include<stdio.h>
#include<limits.h>

class Node
{
    public:
        int src,dest,weight;
};

class Graph
{
    public:
        int V;
        int E;
        Node *edge;
        Graph(int v,int e);
};

Graph:: Graph(int v,int e)
{
    V = v;
    E = e;
    edge = new Node[e];
}

void BellmanFord(Graph *graph,int src)
{
    int V = graph->V;
    int dist[V];

    for(int i=0;i<V;i++)
        dist[i] = INT_MAX;

    dist[src]=0;

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<graph->E;i++)
        {
            int src = graph->edge[i].src;
            int dest = graph->edge[i].dest;
            int wt = graph->edge[i].weight;

            if(dist[src]!=INT_MAX and dist[dest]>dist[src]+wt)
            {
                if(k==V-1)
                    printf("nega!\n");
                else
                    dist[dest] = dist[src]+wt;
            }
        }

    }

    for(int i=0;i<V;i++)
        printf("%d - %d\n",i,dist[i]);

}

// Driver program to test above functions
int main()
{
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph *graph = new Graph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}
