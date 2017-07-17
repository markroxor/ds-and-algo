#include<stdio.h>

class Node
{
    public:
    Node *next;
    int data;
};

class ll
{
    public:
    Node *head;
    void push(int data);
};

void ll::push(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

class Graph
{
    ll *adjList;
    int N;
public:
    Graph(int n);
    void addEdge(int src,int dest);
    void printGraph();
    void graphColoring(int m);
    bool graphColoringUtil(int m,int k,int colors[]);
    bool isSafe(int i,int m,int colors[]);
};

Graph::Graph(int n)
{
    N = n;
    adjList = new ll[n];
    for(int i=0;i<N;i++)
        adjList[i].head = NULL;
}

void Graph::addEdge(int src,int dest)
{
    adjList[src].push(dest);
}

void Graph::printGraph()
{
    for(int i=0;i<N;i++)
    {
        printf("AjList of %d\n",i);
        Node *cur;
        cur = adjList[i].head;

        while(cur)
        {
            printf("%d ",cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

void printArray(int colors[],int n)
{
    printf("Printing array\n");
    for(int i=0;i<n;i++)
        printf("%d ",colors[i]);
    printf("\n");
}

bool Graph::isSafe(int src,int m,int colors[])
{
    Node *cur;
    cur = adjList[src].head;
    
    while(cur)
    {
        if(colors[cur->data] == m)
            return false;
            cur = cur->next;
    }
    
    return true;
    
}


bool Graph::graphColoringUtil(int v,int m,int colors[])
{
    if(v==N)
        return true;

    for(int i=0;i<m;i++)
    {
        if(isSafe(v,i,colors))
        {
            colors[v] = i;
            if(graphColoringUtil(v+1,m,colors))
                return true;
                colors[v] = -1;
        }
    }
    
    return false;
}
void Graph::graphColoring(int m)
{
    int colors[N];
    for(int i=0;i<N;i++)
        colors[i] = -1;

    if(graphColoringUtil(0,m,colors))
    {
        for(int i=0;i<N;i++)
            printf("%d %d\n",i,colors[i]);
        return;
    } 
    
    printf("No Solution");
    return;
}

int main()
{
    Graph  g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,2);
    
    g.printGraph();
    printf("\n");
    g.graphColoring(3);
    return 0;
}
