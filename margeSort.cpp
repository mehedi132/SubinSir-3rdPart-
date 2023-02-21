#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void merge1(int a[],int left,int mid,int right)
{
    int i, sizeLeft, sizeRight, indexA, indexL, indexR;
    sizeLeft = mid - left + 1;
    sizeRight = right - mid;
    int L[sizeLeft], R[sizeRight];
    for (i = 0; i < sizeLeft;i++)
    {
        L[i] = a[left+i]; // merge two sorted array
    }

    for (i = 0; i < sizeRight;i++)
    {
        R[i] = a[mid+1+i];
    }
    indexL = 0;
    indexR = 0;
    for (indexA = left; indexL < sizeLeft && indexR < sizeRight;indexA++)
    {
        if(L[indexL]<R[indexR])
        {
            a[indexA] = L[indexL];
            indexL++;
            
        }
        else{
            a[indexA] = R[indexR];
            indexR++;
            
        }
    }
    while(indexL<sizeLeft)
    {
        a[indexA] = L[indexL];
            indexL++;
            indexA++;
    }


    while(indexR<sizeRight)
    {
        a[indexA] = R[indexR];
            indexR++;
             indexA++;
    }
}


void mergeSort(int a[], int left, int right)
{
    if(left>=right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge1(a, left, mid, right);
}

    int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {5, 4, 9, 8, 20, 14, 3, 6};
int s = sizeof(a) / sizeof(a[0]);
//cout << s;
mergeSort(a, 0, s - 1);
for (int i = 0; i < s;i++)
{
        cout << a[i] << " ";
}
}