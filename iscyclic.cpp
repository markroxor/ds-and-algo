#include<stdio.h>
class Edge
{
    public:
    int src,dest;
};

class Graph
{
    public:
    int V;
    int E;
    Edge *edge;
    Graph(int v,int e);
};

Graph::Graph(int v,int e)
{
    V = v;
    E = e;
    edge = new Edge[e];
}


class Subset
{
    public:
    int rank;
    int par;
};

int find(Subset subset[],int i)
{
    if(subset[i].par==i)
        return i;

    return find(subset,subset[i].par);
}

void Union(Subset subset[],int i,int j)
{
    int ipar = find(subset,i);
    int jpar = find(subset,j);

    if(subset[i].rank<subset[j].rank)
        subset[i].par = jpar;
    else if(subset[i].rank>subset[j].rank)
        subset[j].par = ipar;
    else
    {
        subset[i].rank++;
        subset[j].par = ipar;
    }

}

bool isCycle(Graph graph,int V)
{
    Subset subset[V];
    for(int i=0;i<V;i++)
        subset[i].par=i,subset[i].rank=0;

    for(int k=0;k<graph.E;k++)
    {
        int i=graph.edge[k].src;
        int j=graph.edge[k].dest;

        int pari = find(subset,i);
        int parj = find(subset,j);

        if(pari==parj)
            return true;
        Union(subset,pari,parj);
    }
    return false;
}

int main()
{
        /* Let us create following graph
            0
            |  \
            |    \
            1-----2 */
    int V = 3, E = 3;
    Graph graph(V, E);

    // add edge 0-1
    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;

    // add edge 1-2
    graph.edge[1].src = 1;
    graph.edge[1].dest = 2;

    // add edge 0-2
    //graph.edge[2].src = 0;
    //graph.edge[2].dest = 2;

    if (isCycle(graph,V))
    printf( "Graph contains cycle" );
    else
    printf( "Graph doesn't contain cycle" );

    return 0;
}
