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
    return i/2;
}

int isMaxHeap(int *h,int h_size)
{
    int i, p;
    for (i = h_size; i > 1;i--)
    {
        p = parent(i);
        if(h[p]<h[i])
        {
            
            return 0;
        }
    }
    return 1;
}

void max_Heapify(int *heap,int heap_size,int index)
{

    int l, r,large;
    l = left(index);
    r = right(index);
    if (l <= heap_size && heap[l]>heap[index])
    {
        large = l;
    }
    else{
        large = index;
    }
    if (r <= heap_size && heap[r]>heap[large])
    {
        large = r;
    }
    if(large!=index)
    {
        int t = heap[index];
        heap[index] = heap[large];
        heap[large] = t;
         max_Heapify(heap, heap_size, large);
        
    }
   

}
void heap_print(int *h,int s)
{
    int i;
    for (i = 1; i < s;i++)
    {
         cout << h[i] << " ";
    }
    cout << endl;
}
void build_maxHeap(int *h, int hsize)
{
    int i;
    for (i = hsize / 2; i >= 1;i--)
    {
         max_Heapify(h, hsize, i);
    }
}

void heap_Sort(int *h, int hs)
{
    int i,t;
    for (i = hs; i >= 1;i--)
    {
         t = h[1];
         
         h[1] = h[i];
         h[i] = t;
         hs -= 1;
         max_Heapify(h,hs,1);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

//int h[] = {0, 17, 7, 15, 3, 5, 22, 10, 1, 2};
//int h[] = {0, 12, 7, 1, 3, 10, 17, 19, 2, 5};
int h[] = {0,19, 10 ,17 ,5 ,7, 12 ,1,2 ,3 };
int heapSize = sizeof(h)/sizeof(h[0]);
int a;
heap_print(h, heapSize);
// max_Heapify(h, heapSize - 1, 1);
// heap_print(h,heapSize);
//build_maxHeap(h, heapSize - 1);
//heap_print(h,heapSize);
heap_Sort(h, heapSize - 1);
cout << "after sort" << endl;
heap_print(h, heapSize);

a = isMaxHeap(h, heapSize - 1);
if(a)
{
    cout<<"Its  Max Heap";
}
else{
    cout<<"Its not Max Heap";
}









}