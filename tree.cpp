#include<stdio.h>
using namespace std;

class tNode
{
public:
    tNode *right, *left;
    int value;
    tNode(int n);
};

tNode::tNode(int n)
{
    this->value = n;
    this->left = NULL;
    this->right = NULL;
};

class sNode
{
public:
    sNode *next;
    tNode *tnode;
};

class Stack
{
    sNode *top;
public:
    Stack();
    void push(tNode *root);
    tNode *pop();
    bool isEmpty();
};

Stack::Stack()
{
    top=NULL;
}

void Stack::push(tNode *root)
{
    sNode *temp = new sNode;
    temp->tnode = root;
    temp->next = top;
    top = temp;
};

tNode *Stack::pop()
{
    sNode *poped;
    poped = top;
    top = top->next;
    return poped->tnode;
};

bool Stack::isEmpty()
{
    return top==NULL;
}

void postOrderRec(tNode *root)
{
    if(not root)
        return;

    postOrderRec(root->left);
    postOrderRec(root->right);
    printf("%d->",root->value);
}

void preOrderRec(tNode *root)
{
    if(not root)
        return;

    printf("%d->",root->value);
    preOrderRec(root->left);
    preOrderRec(root->right);
}

void inOrderRec(tNode *root)
{
    if(not root)
        return;

    inOrderRec(root->left);
    printf("%d->",root->value);
    inOrderRec(root->right);
}

void inOrder(tNode *root)
{
    if(root==NULL)
        return;
    Stack s;
    s.push(root);

    tNode *cur = root;

    while(!s.isEmpty())
    {
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.pop();
        printf("%d-",cur->value);
        cur = cur->right;
    }

}

main()
{
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    root->left->left = new tNode(4);
    root->left->right = new tNode(5);
    preOrderRec(root);
    printf("- preOrder \n");
    inOrderRec(root);
    printf("- inOrder \n");
    postOrderRec(root);
    printf("- postOrder \n");
    inOrder(root);
    //Stack s;
    //s.push(1);
    //s.push(2);
    //s.push(3);

    //while(!s.isEmpty())
    //    printf("%d\n",s.pop());
}
