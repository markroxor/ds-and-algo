#include<stdio.h>

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){left=NULL;right=NULL;data=val;};
};

Node *lca(Node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(n1<root->data and n2<root->data)
        return lca(root->left,n1,n2);
    if(n1>root->data and n2>root->data)
        return lca(root->right,n1,n2);
    return root;
}

int minElement(Node *root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root->data;
}

Node *insert(Node *root,int key)
{
    if(root==NULL)
    {
        root = new Node(key);
        return root;
    }

    if(key < root->data)
    {
        root->left =  insert(root->left,key);
    }

    if(key > root->data)
    {
        root->right = insert(root->right,key);
    }
    return root;
}

Node *deleteNode(Node *root,int key)
{
    if(root==NULL)
        return NULL;
    printf("deleteing in root %d\n",root->data);
    if(root->data>key)
    {root =  deleteNode(root->left,key);return root;}
    if(root->data<key)
    {root = deleteNode(root->right,key);return root;}
    Node *cur = root->right;
    if(cur==NULL)
        return root->left;

    printf("cur %d\n",cur->data);
    while(cur->left)
    {cur = cur->left;}

    root->data = cur->data;
    cur=NULL;
    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

/* Driver program to test lca() */
int main()
{
    Node *root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 1;
    // Let us construct the BST shown in the above figure
    Node *root2        = new Node(20);
    root2->left               = new Node(8);
    root2->right              = new Node(22);
    root2->left->left         = new Node(4);
    root2->left->right        = new Node(12);
    root2->left->right->left  = new Node(10);
    root2->left->right->right = new Node(14);

    Node *root1 = insert(NULL,20);
    insert(root1,8);
    insert(root1,22);
    insert(root1,4);
    insert(root1,12);
    insert(root1,10);
    insert(root1,14);


    int n1 = 10, n2 = 14;
    Node *t = lca(root1, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root1, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root1, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    printf("%d\n",minElement(root));
    return 0;
}
