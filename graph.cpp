#include<stdio.h>
#include<stdlib.h>
using namespace std;

class AdjListNode
{
    public:
    int v;
    class AdjListNode *next;
};

class AdjList
{
    public:
    AdjListNode *head;
};

class Graph
{
    public:
    int v;
    AdjList *array;
};

class AdjListNode* newAdjListNode(int dest)
{
    AdjListNode *newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->v = dest;
    newNode->next = NULL;
    return newNode;
};

class Graph *createGraph(int v)
{
    Graph *graph = new Graph;//(Graph*) malloc(sizeof(Graph));
    graph->v = v;
    graph->array = new AdjList[v];// malloc(v * sizeof(AdjList))

    for(int i=0;i<v;i++)
        graph->array[i].head = NULL;
    
    return graph;
};

void addEdge(Graph *graph, int src,int dest)
{
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);

    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode; 
}

void printGraph(Graph *graph)
{
    for(int i=0;i<graph->v;i++)
    {
        AdjListNode *cur = graph->array[i].head;
        while(cur)
            {
                printf("%d->",cur->v);
                cur = cur->next;
            }
        printf("\n");
    }
}

int main()
{
    int V=5;
    Graph *graph = createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph);

    return 0;
}
