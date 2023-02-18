#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct node Node;
struct node
{
    int item;
    Node *next;
    Node *prev;
};

Node *createNewNode(int a, Node *n, Node *p)
{
    Node *createnode = (Node *)malloc(sizeof(Node));
    if(createnode==NULL)
    {
        cout << "ERROR";
    }
    else{
        createnode->item = a;
        createnode->next = n;
        createnode->prev = p;
    }
    return createnode;
}

Node *preaddNode(int a, Node *head)
{
    Node *newnode = createNewNode(a, head, NULL);
    newnode->next->prev = newnode;
    return newnode;
}
Node *append(int a, Node *head)
{
    Node *newnode = createNewNode(a, NULL, NULL);
    if(head==NULL)
    {
        return newnode;
    }
    Node *current = head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
    return head;
}

Node *removenode(Node *head, Node *n)
{
    if(head==n)
    {
        head = n->next;
        head->prev = NULL;
        free(n);
        return head;
    }


  Node *pre = n->prev;
     Node *ne = n->next;
   //  cout <<"Next"<< nex << " "<<preva;
     // n->prev->next  = n->next;
     //  n->next->prev = n->prev;
    // nex->prev = preva;
     //preva->next = nex;
     
     free(n);

     Node *current = head;
     while(current!=NULL)
     {if(current->next==n)
     {
         break;
     }
     current = current->next;
     }

     current->next = ne;
      ne->prev = pre;
     return head;
}

void insertnode(int a, Node *head, int b)
{
     Node *current = head;

    while (current!=NULL)
    {
        
        if(current->item==b)
        {
         break;
        }
        current = current->next;
    }
    
     Node *newnode = createNewNode(a, current->next, current);
                //=createNewNode(a, node->next, node);
     current->next = newnode; //node->next = newnode;
}











    void printNode(Node *head)
{
    Node *current = head;
    if(current==NULL)
    {
        cout << "error";
    }
    while(current!=NULL)
    {
       
        cout << current->item << endl;
        current = current->next;
    }
}



int  main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

Node *head, *n1, *n2, *n3;
n2 = createNewNode(10, NULL, n1);
n1 = createNewNode(220,n2, NULL);
head = n1;
head = preaddNode(150, head);
head = append(50, head);
printNode(head);
//head = removenode(head, n2);
insertnode(25, head,150);
printNode(head);
}