#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define M 4
typedef struct{
    int top;
    int data[M];
}stak;
 void push1( stak *s, int n)
 {
    if(s->top<M)
    {
        s->data[s->top] = n;
        s->top=s->top+1;
    }
    else{
        cout << "Stack is full";
    }
 }

 int pop1(stak *s)
 {
    int a;
    if(s->top==0)
    {
        cout << "Stack is empty";
        return -1;
    }
    else{
        s->top=s->top-1;
        a = s->data[s->top];
        
        return a;
    }
 }

int main()
{
     #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
stak a;
a.top = 0;
push1(&a, 2);
push1(&a, 23);
push1(&a, 6);
push1(&a, 5);
push1(&a, 50);

        int b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
 b = pop1(&a);
cout<<b<<endl;
}