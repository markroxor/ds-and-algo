/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{    if(node->next and node->next->next==NULL)
    {
        node->data=node->next->data;
        node->next=NULL;
        return;

    }
    while(node->next)
    {
        node->data=node->next->data;
        node=node->next;
    if(node->next and node->next->next==NULL)
    {
        node->data=node->next->data;
        node->next=NULL;
        return;

    }
        
    }
}
