#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *createNewNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void addleft(Node *parent, Node *child)
{
    parent->left = child;
    if(child!=NULL)
    {
        child->parent = parent;
    }      
}

void addright(Node *parent, Node *child)
{
    parent->right = child;
    if(child!=NULL)
    {
        child->parent = parent;
    }
}

Node *bstInsert(Node *root, Node *node)
{
    Node *current, *parent;
    current = root;
    while(current!=NULL)
    {
        parent = current;
        if(node->data>current->data)
        {
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
    if(node->data>parent->data)
        {
        addright(parent, node);
        }
        else{
        addleft(parent, node);
        }
        return root;
}
void printPreorder(Node *root)
{
        cout << root->data << " ";
        if(root->left!=NULL)
        {
        printPreorder(root->left);
        }
        if(root->right!=NULL)
        {
        printPreorder(root->right);
        }
}

Node *createbst(Node *root,int a[],int s)
{
        int i;
        Node *node;
        for (i = 1; i < s;i++)
        {
        node = createNewNode(a[i]);
        root = bstInsert(root, node);
        }
        return root;
}

Node *minimum(Node *root)
{
        Node *current = root;
        while(current->left!=NULL)
        {
        current = current->left;
        }
       // v cout << "small " << current->data;
        return current;
}

Node *bst_Transfer(Node *root,Node *currnet,Node *node)
{
    if(currnet==root)
    {
        root = node;
    }
    else if(currnet==currnet->parent->left)
    {
        addleft(currnet->parent, node);
    }
    else{
        addright(currnet->parent, node);
    }
    return root;
}

Node *bst_delete(Node *root,Node *node)
{
    if(node->left==NULL)
    {
        root=bst_Transfer(root,node, node->right);
    }
    else if(node->right==NULL)
    {
      root= bst_Transfer(root,node, node->left);
    }
    else{

        Node *min = minimum(node->right);
        if(min!=node->right)
        {
   root = bst_Transfer(root, min, min->right);
   addright(min, node->right);
        }
        root = bst_Transfer(root, node, min);
        addleft(min, node->left);
       
    }
     free(node);
    return root;

}

Node *searchNode(Node *root,int a)
{
    Node *current = root;
    while(current!=NULL)
    {
        if(current->data==a)
        {
            return current;
        }
        if(a<current->data)
        {
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    
}

void inorder(Node *root)
{
   
    if(root->left!=NULL)
    {
        inorder(root->left);
    }

    cout << root->data << " ";
    if(root->right!=NULL)
    {

        inorder(root->right);
    }
     
}







int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[]={10,5,17,3,7,12,19,1,4};
int s = sizeof(a) / sizeof(a[0]);
Node *root,*n;
root = createNewNode(a[0]);
root = createbst(root, a, s);
inorder(root);
cout << endl;
n = minimum(root);

n = searchNode(root, 1);
if(n!=NULL)
{
        cout << "Will delete " << n->data << " from BST" << endl;
        root = bst_delete(root, n);
        cout << "After delete in inorder" << endl;
        inorder(root);
        cout << endl;

}
else{
        cout << "Data not found" << endl;
}

n = searchNode(root, 5);
if(n!=NULL)
{
        cout << "Will delete " << n->data << " from BST" << endl;
        root = bst_delete(root, n);
        cout << "After delete in inorder" << endl;
        inorder(root);
           cout << endl;
}
else{
        cout << "Data not found" << endl;
}

n = searchNode(root, 10);
if(n!=NULL)
{
        cout << "Will delete " << n->data << " from BST" << endl;
        root = bst_delete(root, n);
        cout << "After delete in inorder" << endl;
        inorder(root);
           cout << endl;
}
else{
        cout << "Data not found" << endl;
}






}