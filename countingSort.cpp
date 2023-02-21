#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void countingSort(int a[],int s)
{
  // non comparision sort
    int m=a[0];
    int i;
    for ( i = 0; i < s-1;i++)
    {
        if(a[i]<a[i+1])
        {
            m = a[i + 1];
        }
    }
    int coun[s+ 1];
    for (i = 0; i < s;i++)
    {
        coun[i] = 0;
    }

    for (i = 0; i < s;i++)
    {
        coun[a[i]] = coun[a[i]]+1;
    }

    for ( i = 0; i < s;i++)
    {
        if(coun[i]!=0)
        {
            int t = coun[i];
            while(t>0)
            {
                cout << i << " ";
                t--;
            }
            
        }
    }
    
}


int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {5, 8, 6, 5, 7, 9,1, 6, 7,3,2,3,9, 6};
int s = sizeof(a) / sizeof(a[0]);
countingSort(a,s);
}