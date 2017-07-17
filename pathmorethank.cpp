#include<stdio.h>
#include<iostream>
using namespace std;

class Graph
{
    int V;
    int *arr;
public:
    Graph(int v);
    void addEdge(int u,int v,int w);
    void printGraph();
    bool pathMoreThanK(int src,int k); 
    bool pathMoreThanKUtil(int src,int k,int path[]);
};

Graph::Graph(int v)
{
    V = v;
    arr = new int[v*v];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            arr[i*V+j] = -1;

}

void Graph::addEdge(int u,int v,int w)
{
    arr[u*V+v] = w;
    arr[v*V+u] = w;
}

void Graph::printGraph()
{

    for(int i=0;i<V;i++)
    {
        printf("%d-",i);
        for(int j=0;j<V;j++)
            printf("%d ",arr[i*V+j]);
        printf("\n");
    }
}

bool Graph:: pathMoreThanKUtil(int src,int k,int path[])
{
    if(k<0)
        return true;

    for(int i=0;i<V;i++)
    {
        int child = src*V+i;

        if(arr[child]==-1 or path[i])
            continue;

        int cur_wt = arr[child];

        
        path[i]=1;
        if(pathMoreThanKUtil(i,k-cur_wt,path))
            return true;

        path[i]=0;
    }
    
    return false;
}

bool Graph:: pathMoreThanK(int src,int k)
{
    int path[V];
    for(int i=0;i<V;i++)
        path[i] = 0;
    
    path[src] = 1;
    return (pathMoreThanKUtil(src,k,path));
}


int main()
{
        // create the graph given in above fugure
    int V = 9;
    Graph g(V);
    
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.printGraph();

    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
    cout << "No\n";

    k = 60;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
    cout << "No\n";

    return 0;
}
