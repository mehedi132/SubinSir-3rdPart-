#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define max1 9999

int partition(int a[],int l,int r)
{
    int pivot = a[l];
    int i, j;
    i = l;
    j = r;
   while(i<j)
   {
    while(a[i]<pivot)
    {
        i++;
    }
    while(a[j]>pivot)
    {
        j--;
    }
    if(i<j)
    {
        swap(a[i], a[j]);
    }
   }
   swap(pivot, a[j]);
   return j;

}
void QuickSort(int a[],int l, int r)
{
    if(l<r)
    {
    int j = partition(a, l, r);
    QuickSort(a, l, j);
    QuickSort(a, j + 1, r);
    }
}

    int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {5, 7, 4, 9, 6, 2, 1, 3, 8,max1};
int s = sizeof(a) / sizeof(a[0]);
//cout << s;

QuickSort(a, 0, s - 1);
for (int i = 0; i < s-1;i++)
{
        cout << a[i] << " ";
}
}