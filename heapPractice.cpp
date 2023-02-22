#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i+1;
}

int parent(int i)
{
    return  i/2;
}

int ismaxheap(int a[],int s)
{
    int p;
    for (int i = s; i > 1;i--)
    {
        p = parent(i);
        if(a[p]<a[i])
        {
            
            return 0;
        }
    }
    return 1;
}

    void maxheapify(int a[], int s, int index)
{
    int large=0;
    int l = left(index);
    //cout << "lol"<<l;
    int r = right(index);
    if (l<=s && a[index]<a[l])
    {
        large = l;
    }
    else{
        large = index;
    }
    if(r<=s && a[r]>a[large])
    {
        large = r;
    }
    if(large!=index)
    {
int t = a[index];
    a[index] = a[large];
    a[large] = t;
    maxheapify(a,s,large);
    }
    
}

void maxheap(int a[], int s)
{
    int i;
    for (i = s / 2; i > 0; i--)
    {
        maxheapify(a,s-1, i);
    }
}

void heapSort(int a[],int s)
{
    for (int i = s; i > 0;i--)
    {
      int p = a[1];
    a[1] = a[i];
    a[i] = p;
    s--;
    maxheapify(a, s, 1);



    }
        
}









void printheap(int a[],int s)
{
    for (int i = 1; i < s;i++)
    {
        cout << a[i] << " ";
    }
}





    int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int h[] = {0,19, 10 ,17 ,50 ,7, 12 ,1,2 ,3 };
int heapSize = sizeof(h)/sizeof(h[0]);

int a;
maxheap(h, heapSize-1);
printheap(h, heapSize);
cout << endl;
a = ismaxheap(h,heapSize-1);
cout << a << endl;
if(a)
{
        cout << "Max Heap" << endl;
}
else{
    cout << "not Max Heap" << endl;
}
heapSort(h, heapSize - 1);
cout << "after sort" << endl;

printheap(h, heapSize);


}