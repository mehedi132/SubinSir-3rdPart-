#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int a)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = a;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void addleft(Node *node, Node *child)
{
    node->left = child;
}
void addright(Node *node, Node *child)
{
    node->right = child;
}

Node *createTree()
{
    Node *two = createNode(2);
    Node *seven = createNode(7);
    Node *nine = createNode(9);
    addleft(two, seven);
    addright(two, nine);
    Node *one = createNode(1);
    Node *six = createNode(6);
    Node *eight = createNode(8);
    addleft(seven, one);
    addright(seven, six);
    addright(nine, eight);
    Node *five = createNode(5);
    Node *ten = createNode(10);
    Node *three = createNode(3);
    Node *four = createNode(4);
    addleft(six, five);
    addright(six, ten);
    addleft(eight, three);

    addright(eight, four);

    return two;
}

void preOrder(Node *node)
{
    cout << node->data << " ";
    if(node->left!=NULL)
    {
        preOrder(node->left);
    }
    if(node->right!=NULL)
    {
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if(node->left!=NULL)
    {
        postOrder(node->left);

    }
    if(node->right!=NULL)
    {
        postOrder(node->right);
    }
    cout << node->data << " ";

}

void inOrder(Node *node)
{
    if(node->left!=NULL)
    {
        inOrder(node->left);
    }
    cout << node->data << " ";
    if(node->right!=NULL)
    {
        inOrder(node->right);
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
     Node *root;
    root = createTree();
    //cout << root->data<<endl;
    cout << "Travers in PreOrder" << endl; //root-left-right
    preOrder(root);
    cout << endl;
    cout << "Travers in PostOrder" << endl; //root-left-right
    postOrder(root);
  cout << endl;
    cout << "Travers in InOrder" << endl; //root-left-right
    inOrder(root);
    // while(root!=NULL)
    // {
    //    cout << root->data<<endl;
    //    root = root->left;
    // }
   // cout << root->left->right->right->data;
}