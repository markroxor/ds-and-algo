#include<stdio.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

void reversell(Node **head)
{
    if(*head==NULL)
        return;

    Node *cur = *head;
    Node *next = (*head)->next;
    Node *prev=NULL;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    *head=prev;
}

void push(Node **head,int data)
{
    Node *newNode=new Node;
    newNode->next = (*head);
    newNode->data = data;

    *head = newNode;
}

void printList(Node *head)
{
    Node *cur = head;
    while(cur)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node  *merge(Node *a,Node *b)
{
    Node *cur=new Node;

    Node *cur1 = a,*cur2 = b;

    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

        if(cur1->data<=cur2->data)
        {
            cur->data = cur1->data;
            cur->next = merge(a->next,b);
        }
        else
        {
            cur->data = cur2->data;
            cur->next = merge(a,b->next);
        }

        return cur;

}

//root(p) stores address of node a and b(pp) store address of pointers(address).
//a
//slow = j a = k
//*a = value in slow/root

void split(Node *root,Node **a,Node **b)
{
    Node *slow;
    Node *fast;
    
    if(root ==NULL or root->next==NULL)
    {
        *a=root;
        *b=NULL;
        return;
    }
    
    slow = root;
    fast = root->next;

    while(fast)
    {
        fast = fast->next;
        if(fast)
        {
            slow = slow->next;
            fast=fast->next;
        }
    }
    
    //*a and *b is the location of address it stored
    *a = root;
    //the place that a points to has value - 
    *b = (slow->next);
    slow->next = NULL;
    
}

void mergeSort(Node **root)
{
    Node *a,*b;
    if(*root==NULL or (*root)->next==NULL)
        return;
    
    // passing address of pointers
    split(*root,&a,&b);
    mergeSort(&a);
    mergeSort(&b);

    *root = merge(a,b);
}
int main()
{
/* Start with the empty list */
    Node* head = NULL;
    
    push(&head, 20);
    push(&head, 4);
    push(&head, 15); 
    push(&head, 85);      
    
    printf("Given linked list\n");
    printList(head);    
    mergeSort(&head);                      
    printf("\nReversed Linked list \n");
    printList(head);    
}
