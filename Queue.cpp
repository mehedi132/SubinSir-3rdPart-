#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define M 5
typedef struct{
    int front;
    int tail;
    int data[M+1];
}q;

void enque1( q *s, int n)
 {
    if((s->tail+1)%(M+1)== s->front)
    {
        cout << "Queue is full ";
        cout << "after11 " << s->tail<<s->front << endl;
    }
    else{
        s->data[s->tail] = n;
        cout << "before " << s->tail <<" "<< n << " ";
        s->tail = (s->tail+1)%(M+1);
        cout << "after " << s->tail << endl;
        
    }
 }

 int pop1(q *s)
 {
    int a;
    if(s->tail==s->front)
    {
        cout << "q is empty";
        cout << "f " << s->front << endl;
        cout << "f " << s->tail << endl;
        return -1;
    }
    else{
        
        a = s->data[s->front];
        s->front=s->front+1;
        cout << "f " << s->front << endl;

        return a;
    }
 }

int main()
{
     #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
q a;
a.front = 0;
a.tail = 0;
enque1(&a, 2);
enque1(&a, 23);
enque1(&a, 6);
enque1(&a, 5);
enque1(&a, 69);


int b = pop1(&a);
cout<<b<<endl;

 b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
  enque1(&a, 50);
 enque1(&a, 55);
  enque1(&a, 560);
   enque1(&a, 5547);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
}