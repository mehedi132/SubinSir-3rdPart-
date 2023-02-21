#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 int partision(int a[],int l,int r)
 {
     int pivot = a[r];
     int i = l-1;
     int j=l;
     int t;
    
     while(j<r)
     {
        if(a[j]>a[r])
        {
            j++;
        }
        else{
            i++;
           t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
     }
     t = a[i + 1];
     a[i + 1] = a[r];
     a[r] = t;
     return i;
    }
   
     
 

 void quicksort(int a[], int l, int r){
    if(l>=r)
    {
        return;
    }
     int j = partision(a, l, r);
     
     quicksort(a, l, j);
     quicksort(a, j + 2, r);
 }

int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {6, 4, 1,9,14,5};
int s = sizeof(a) / sizeof(a[0]);
cout << s << endl;
quicksort(a, 0, s - 1);
for (int i = 0; i < s;i++)
{
        cout << a[i] << " ";
}
}