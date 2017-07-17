#include<stdio.h>

class Queue
{
    int front,rear, size;
    int *array;
    int capacity;
public:
    Queue(int capacity);
    bool isFull();
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int Front();
    int Rear();

};

Queue::Queue(int cap) 
{
    capacity = cap;
    front = size = 0;
    rear = capacity-1;
    array = new int[capacity];
}

bool Queue::isFull()
{
    return size==capacity;
}

bool Queue::isEmpty()
{
    return not size;
}

void Queue::enqueue(int item)
{
    if(isFull())
        return;
    size++;
    ++rear%=capacity;
    array[rear] = item;
}

int Queue::dequeue()
{
    if(isEmpty())
        return -1;
    size--;
    int item = array[front];
    ++front%=capacity;

    return item;
}

int Queue::Front()
{
    if(isEmpty())
        return -1;
    return array[front];
}

int Queue::Rear()
{
    if(isEmpty())
        return -1;
    return array[rear];
}


class Stack
{
    int capacity;
    int cur;
    char *array;
public:
    Stack(int n);
    char pop();
    bool isEmpty();
    void push(char c);
    char peek();
};

Stack::Stack(int cap)
{
    capacity = cap;
    array = new char[cap];
    cur=0;
};

char Stack::pop()
{
    return array[--cur];
};

char Stack::peek()
{
    return array[cur-1];
}

void Stack::push(char c)
{
    array[cur++]=c;
}

bool Stack::isEmpty()
{
    return not cur;
}

class Node
{
public:
    int v;
    Node *next;
};


class list
{
    public:
    Node *head;
};


class Graph
{
    list *mesh;
    int n;

public:
    Graph(int n);
    void addEdge(int x,int y);
    void printGraph();
    void dfs();
    void bfs(int n);
};


Graph::Graph(int n)
{
    this->n = n;
    this->mesh = new list[n];

    for(int i=0;i<n;i++)
        this->mesh[i].head = NULL;
};


void Graph::addEdge(int x, int y)
{

    Node *node = new Node;
    node->v = y;
    node->next = this->mesh[x].head;
    
    this->mesh[x].head = node;
     
   // node = new Node;
   // node->v = x;
   // node->next = this->mesh[y].head;
   // this->mesh[y].head = node;
    
};


void Graph::printGraph()
{
    for(int i=0; i<this->n; i++)
    {
        printf("Adj list of vertex %d\n",i);
        Node *cur = this->mesh[i].head;
        while(cur)
        {
            printf("%d->",cur->v);
            cur = cur->next;
        }
        printf("\n");
    }

};

void Graph::dfs()
{
    printf("DFS\n");
    int visited[this->n];
    for(int i=0;i<this->n;i++)
        visited[i] = 0;
    

    for(int i=0;i<this->n;i++)
    {
        Node *cur = this->mesh[i].head;
        
        if(not visited[i])
            printf("\nroot %d ->\n",i);
        
        visited[i] = 1;

        while(cur)
        {
            if(not visited[cur->v])
            {    
                printf("%d->",cur->v);
                visited[cur->v] = 1;
            }
            cur = cur->next;
        }
    }
        printf("\n");
}

void Graph::bfs(int src)
{
    Queue q(n);
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    
    q.enqueue(src);
    visited[src] = 1;
    
    while(!q.isEmpty())
    {

        int root = q.dequeue();
        printf("%d-",root);
        Node *cur = mesh[root].head;
        visited[root] = 1;
        

        while(cur)
        {
            if(!visited[cur->v])
            {
                q.enqueue(cur->v);
                visited[cur->v] = 1;
            }
            cur = cur->next;
        }
    }
        printf("\n");
}

int main()
{
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(2,3);
    graph.addEdge(3,3);

    graph.printGraph();
 
    printf("Following is Breadth First Traversal(starting from vertex 2) \n");


    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    graph.bfs(2);
    g.dfs();
                                 
    return 0;
}



