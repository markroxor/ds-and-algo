#include<stdio.h>
using namespace std;

class tNode
{
public:
    int data;
    tNode *left,*right;
    tNode(){left=right=NULL;}
};

class Node
{
public:
    tNode *tnode;
    Node *next;
};

class Queue
{
    Node *rear,*front;
public:
    Queue(){rear=NULL,front=NULL;}
    void Enqueue(tNode *root);
    tNode *Dequeue();
    
};

void Queue::Enqueue(tNode *root)
{
    Node *temp = new Node;
    temp->next = NULL;
    temp->tnode = root;
    
    if(rear==NULL)
    {
        rear  = new Node;
        rear->next = NULL;
        rear->tnode=root;
        front = rear;
        return;
    }
    rear->next = temp;
    rear = rear->next;
};

tNode *Queue::Dequeue()
{
    if(front==NULL)
        return NULL;

    tNode *temp = front->tnode;
    front = front->next;
    
    if(front==NULL)
        rear=NULL;
    return temp;
};

int main()
{
    Queue q;
    tNode *root = new tNode;
    root->data = 10;
    q.Enqueue(root);
    root = new tNode;
    root->data = 20;
    q.Enqueue(root);
    q.Dequeue();
    q.Dequeue();
    root = new tNode;
    root->data = 30;
    q.Enqueue(root);
    root = new tNode;
    root->data = 40;
    q.Enqueue(root);
    root = new tNode;
    root->data = 50;
    q.Enqueue(root);
    tNode *n = q.Dequeue();

    if (n != NULL)
    printf("Dequeued item is %d", n->data);
    return 0;
}
