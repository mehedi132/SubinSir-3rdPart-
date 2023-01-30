#include<bits/stdc++.h>
using namespace std;
void printtarr(int a[],int n)
{
    for (int i = 0; i < n;i++)
{
        cout << a[i] << " ";
}
}

void selectionSort(int a[], int n)
{
    int i,j,z;
    int positon = 0;
    for (i = 0; i < n - 1;i++)
    {
        int min = a[i];
        z = 0;
        positon = -1;

        for (j = i + 1; j < n;j++)
        {
            
            //cout<<"min "<<j<<endl
            
            if(min>a[j])
            {
                z++;
                min = a[j];
                positon = j;
            }
        }
        if(positon>=0)
        {
            int t = a[i];
        a[i] = a[positon];
        a[positon] = t;
        cout << "after " << i + 1<<endl;
        printtarr(a, n);
        cout << endl;

        }
        
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {1,1,1,2};
int n = sizeof(a) / sizeof(a[0]);
selectionSort(a, n);
cout<<"final"<<endl;

printtarr(a, n);
}