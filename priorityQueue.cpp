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
void printHeap(int *h,int s){
    for (int i = 1; i <=s;i++)
    {
        cout << h[i] << " ";
    }
    cout << endl;
}

void Max_heapify(int *h,int hsize, int index)
{
    int t, l, r,large;
    l = left(index);
    
    
    r = right(index);
      
    if(l<=hsize && h[l]>h[index])
    {
        large = l;
        
    }
    else{
        large = index;
    }
    if(r<=hsize && h[r]>h[large])
    {
        large = r;
          
    }
    if(large!=index)
    {
        
        t = h[index];
        
        h[index] = h[large];
        
        h[large] = t;
       

        Max_heapify(h, hsize, large);
    }

}

void Max_heapConstruct(int *h,int hsize)
{
    int i;
    for (i = hsize / 2; i >= 1;i--)
    {
        Max_heapify(h, hsize, i);
    }
}
int extractPriority(int *h,int hs)
{
        int t;
        t = h[1];
        h[1] = h[hs];   
           
        cout << "max priority " << t<< endl;
        hs--;
        Max_heapify(h, hs, 1);
        return hs;
}

int addNodePriorityQ(int *h,int hs, int a)
{
        hs++;
        h[hs] = a;
        int i, j,p;
        i = hs;
      //  p = parent[i];
        while(i>1 && h[i]>h[parent(i)])
        {
        p = parent(i);
        j = h[p];
        h[p] = h[i];
        h[i] = j;
        i = p;
        }
        return hs;
}






int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int h[] = {0, 10, 17, 3, 2, 19, 12, 7, 1,5 };

int hsize = sizeof(h) / sizeof(h[0]);
//cout << hsize;
printHeap(h, hsize-1);

Max_heapConstruct(h, hsize-1 );
printHeap(h, hsize-1);

hsize=addNodePriorityQ(h, hsize-1, 15);
printHeap(h, hsize);
//cout << hsize;
hsize = extractPriority(h, hsize);
printHeap(h, hsize);
hsize = extractPriority(h, hsize);
printHeap(h, hsize);
//printHeap(h, hsize);





}


