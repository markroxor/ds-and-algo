#include <stdio.h>

class Node
{
    public:
    int data;
    Node *next;
};

void push(Node **node,int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(*node==NULL)
    {
        *node = newNode;
        return;
    }

    newNode->next = *node;
    *node = newNode;
}

void printList(Node *node)
{
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
}

int swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void pairWiseSwap(Node *head)
{
    
    while(head!=NULL and (head)->next!=NULL)
    {
//        printf("%d %d\n",(head)->data,(head)->next->data);
        swap((head)->data,(head)->next->data);
//        printf("%d %d\n",(head)->data,(head)->next->data);
        head=head->next;
        if(head)
            head=head->next;
    }

}

int main()
{
    Node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    pairWiseSwap(start);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
 
    return 0;
}
