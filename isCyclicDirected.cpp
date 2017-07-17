#include<stdio.h>

class Node
{
    public:
    int value;
    Node *next;
    Node(int v){value=v,next=NULL;}
};

class graph
{
public:
    int V;
    Node *adjList;
    Graph(int v){V=v;adjList = new Node[v];};
    void addEdge(int src,int dest);
};



int main()
{
        // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    return 0;
}
