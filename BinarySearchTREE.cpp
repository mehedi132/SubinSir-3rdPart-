#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *createnewNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void addLeftnode(Node *node, Node *child)
{
    node->left = child;
    if(child    !=NULL )
    {
        child->parent = node;
    }
}

void addrightnode(Node *node, Node *child)
{
    node->right = child;
    if(child    !=NULL )
    {
        child->parent = node;
    }
}

Node *btsInsert(Node *root, Node *node)
{
    Node *parent, *current;
    current = root;
    if(root==NULL)
    {
        root = node;
        return root;
    }
    while (current!=NULL)
    {
        parent = current;
        if(node->data<current->data)
        {
            current = current->left;
        }
        else{
            current = current->right;
        }
    }

    if(node->data> parent->data)
    {
        addrightnode(parent, node);
    }
    else{

        addLeftnode(parent, node);
    }
    return root;
}

Node *createBST()
{
    Node *root,*node;
    int a[]={5,17,3,7,12,19,1,4};
    root = createnewNode(10);
    for (int i = 0; i < 8;i++)
    {
        node = createnewNode(a[i]);
        root = btsInsert(root, node);
    }

    return root;
}

void preeorder(Node *root)
{
    cout << root->data << " ";
    if(root->left!=NULL)
    {
        preeorder(root->left);
    }
    if(root->right!=NULL)
    {

        preeorder(root->right);
    }
}
void postorder(Node *root)
{
   
    if(root->left!=NULL)
    {
        postorder(root->left);
    }
    if(root->right!=NULL)
    {

        postorder(root->right);
    }
     cout << root->data << " ";
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
Node * smallestdata(Node *root)
{
    Node *current = root;
    while (current->left!=NULL)
    {
        current = current->left;
    }
    //cout << "Smallest Data is: " << current->data<<endl;
    return current;
}

void biggestdata(Node *root)
{
    Node *current = root;
    while (current->right!=NULL)
    {
        current = current->right;
    }
    cout << "Biggest Data is: " << current->data<<endl;
}

Node *bst_transplant(Node *root, Node *current, Node *new1)
{
    if(current==root)
    {
        root = new1;

    }
    else if(current=current->parent->left)
    {
        addLeftnode(current->parent, new1);

    }
    else{
        addrightnode(current->parent, new1);

    }
    return root;
}

Node *delete_BST(Node *root, Node *node)
{
    Node *smallest;
    if(node->left==NULL)
    {

        root = bst_transplant(root, node, node->right);
    }
    else if(node->right==NULL)
    {
        root = bst_transplant(root, node, node->left);
    }
    else{
        smallest = smallestdata(node->right);
        if(smallest->parent!=node)
        {
            root = bst_transplant(root, smallest, smallest->right);
            addrightnode(smallest, node->right);
        }
        root = bst_transplant(root, node, smallest);
        addLeftnode(smallest, node->left);
    }
    free(node);
    return root;
}









int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
Node *root,*n;
root = createBST();
//cout << "PreOrder" << endl;
//preeorder(root);
cout << endl;
//cout << "PostOrder" << endl;
//postorder(root);
cout << endl;
cout << "InOrder" << endl;
inorder(root);
cout << endl;
n = searchNode(root, 1);
if(n!=NULL)
{
        cout << "Will delete " << n->data << " from BST" << endl;
        root = delete_BST(root, n);
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
        root = delete_BST(root, n);
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
        root = delete_BST(root, n);
        cout << "After delete in inorder" << endl;
        inorder(root);
           cout << endl;
}
else{
        cout << "Data not found" << endl;
}

// n = searchNode(root, 70);
// if(n!=NULL)
// {
//         cout << "data Found";
//         cout << endl;
// }
// else{
//         cout << "data Not found";
//         cout << endl;
// }

// smallestdata(root);
// biggestdata(root);

}