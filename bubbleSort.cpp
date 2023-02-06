#include<bits/stdc++.h>
using namespace std;
void printtarr(int a[],int n)
{
    for (int i = 0; i < n;i++)
{
        cout << a[i] << " ";
}
}

void bubbleSort(int a[], int n)
{
    int i,j,z;
    
    for (i = 0; i < n;i++)
    { for (j = 0; j < n-1;j++)
        { 
    
            
            if(a[j]>a[j+1])
            {
                int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        cout << "after " << i + 1<<endl;
        printtarr(a, n);
        cout << endl;
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
int a[] = {14,12,11,9,8,7,6,5,4};
int n = sizeof(a) / sizeof(a[0]);
bubbleSort(a, n);
cout<<"final"<<endl;

printtarr(a, n);
}