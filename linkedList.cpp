#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct node Node;
struct node
{
     int d;
     Node *next;
};

Node *createNode(int a, Node *next)
{
     Node *newNode = (Node *)malloc(sizeof(Node));
     if(newNode==NULL)
     {
          cout << "Error";
     }
     newNode->d = a;
     newNode->next = next;
     return newNode;
}

Node *preadd(int a, Node *head) // add first
{
     Node *first = createNode(a, head);
     return first;
}

Node *appendNode(Node *head,int a) // add last
{ 
     Node *newNode = createNode(a, NULL);
     if(head==NULL)
     { 
          return newNode;
     }
     Node *currentNode = head;

     while(currentNode->next!=NULL)
     {
          currentNode = currentNode->next;
     }
     currentNode->next = newNode;
    
     return head;
}

Node *removeNode(node *head,Node *node)
{
     if(head==node)
     {
          head = node->next;
          return head;
     }
     Node *currennt = head;
     while(currennt!=NULL)
     {
          if(currennt->next==node)
          {
               break;
          }
          currennt = currennt->next;
     }
     if(currennt==NULL)
     {
          return head;
     }
     currennt->next = node->next;
     return head;
}

Node *removeNode1(node *head,int a)

{
  Node *node = head;

     while(node!=NULL)
     {
          if(node->d==a)
          {
               
               break;
          }
          node = node->next;
     }

     if(head==node)
     {
          head = node->next;
          return head;
     }
     Node *currennt = head;
     while(currennt!=NULL)
     {
          if(currennt->next==node)
          {
               break;
          }
          currennt = currennt->next;
     }
     if(currennt==NULL)
     {
          return head;
     }
     currennt->next = node->next;
     return head;
}

void insertafter(Node *a, int i)
{
     Node *newNode = createNode(i, a->next);
     a->next = newNode;
}

void printNode(Node *head)
{
     Node *current = head;
     while (current!=NULL)
     {
          cout << current->d << endl;
          current = current->next;
     }
     

}

    int main()
{
     #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

Node *head, *n1, *n2, *n3;

 n1 = createNode(10, NULL);
 //cout << n1->d;
 head = n1;
 printNode(head); //10
// n2 = preadd(20, head);

  head = preadd(20, head);
   n2 = head;
  //head = n2;
   // printNode(head);//20 10
    head = appendNode(head,30);
    printNode(head);//20 10 30
    //head = removeNode(head, n1); // through node
     head = removeNode1(head, 30);// through value
    printNode(head);//20 30
    insertafter(n2, 40);
    printNode(head);

    //   cout << "first" << n2->d << endl;
    //   //cout << "first add" << n2->next << endl;
    //   n3 = n2->next;
    //   cout << "sec" << n3->d<<endl;
    //   //cout << "sec aDD" << n3->next;

}