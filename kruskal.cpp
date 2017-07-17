#include<stdio.h>

class Subset
{
public:
    int rank;
    int par;
};


class Edge
{
    public:
    int src;
    int dest;
    int weight;
};

class Graph
{
    public:
    int V,E;
    Edge *edge;
    Graph(int v,int e){V=v,E=e,edge = new Edge[E];};
};


void swap(Edge *a,Edge *b)
{
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Graph *graph,int low,int high)
{
    int k=low,pivot = graph->edge[high].weight;
    for(int i=low;i<high;i++)
        if(graph->edge[i].weight<=graph->edge[high].weight)
            swap(&graph->edge[i],&graph->edge[k++]);

    swap(&graph->edge[k],&graph->edge[high]);
    return k;
}

void qsort(Graph *graph,int low,int high)
{
    if(low<high)
    {
        int piv = partition(graph,low,high);
        qsort(graph,low,piv-1);
        qsort(graph,piv+1,high);
    }
}

int find(Subset subset[],int i)
{
//    printf("finding i is %d \n",i);
    if(subset[i].par==i)
        return i;

    return find(subset,subset[i].par);
}

void Union(Subset subset[],int i,int j)
{
    int pari = find(subset,i);
    int parj = find(subset,j);

    if(subset[pari].rank<subset[parj].rank)
        subset[pari].par = parj;
    else if(subset[pari].rank>subset[parj].rank)
        subset[parj].par = pari;
    else
        subset[pari].par = parj,subset[parj].rank++;
}

void KruskalMST(Graph *graph,int V,int E)
{
    Subset subset[V];
    for(int i=0;i<V;i++)
        subset[i].par = i,subset[i].rank = 0;

    qsort(graph,0,E-1);
    for(int i=0;i<E;i++)
    {
        //printf("foring\n");
        int pars = find(subset,graph->edge[i].src);
        int pard = find(subset,graph->edge[i].dest);
        //printf("find fine\n");
        if(pars==pard)
            continue;

        //printf("e\n");
        printf("%d %d %d\n",graph->edge[i].src,graph->edge[i].dest,graph->edge[i].weight);
        Union(subset,graph->edge[i].src,graph->edge[i].dest);
        //printf("printing subset\n");
        //for(int i=0;i<V;i++)
            //printf("%d %d\n",subset[i].par,subset[i].rank);
    }

}

int main()
{
    /* Let us create following weighted graph
    10
    0--------1
    |  \     |
    6|   5\   |15
    |      \ |
    2--------3
    4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph graph(V, E);


    // add edge 0-1
    graph.edge[0].src = 0;
    graph.edge[0].dest = 3;
    graph.edge[0].weight = 5;

    // add edge 0-2
    graph.edge[1].src = 0;
    graph.edge[1].dest = 2;
    graph.edge[1].weight = 6;

    // add edge 0-3
    graph.edge[2].src = 0;
    graph.edge[2].dest = 1;
    graph.edge[2].weight = 10;

    // add edge 1-3
    graph.edge[3].src = 1;
    graph.edge[3].dest = 3;
    graph.edge[3].weight = 15;

    // add edge 2-3
    graph.edge[4].src = 2;
    graph.edge[4].dest = 3;
    graph.edge[4].weight = 4;

    KruskalMST(&graph, V, E);

    return 0;
}
