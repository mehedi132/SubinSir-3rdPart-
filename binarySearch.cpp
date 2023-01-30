#include<bits/stdc++.h>
using namespace std;
void binarySearch(int a[] ,int n)
{ // need sorted array
    int l, r, m,f,z=0;
    cin >> f;
    l = 0;
    r = n - 1;


    while(l<=r)
    {
         m = (l + r) / 2;
         
         if (a[m] == f)
         {
             z = 1;
             cout << "find at position " << m;
             break;
    }
    else if(f>a[m])
    {
        l = m + 1;
    }
    else{
        r = m - 1;
    }

    }
    if(z==0)
    {
cout<<"not found";
    }
    
}




int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int  row, col,i;

int a[] = {20, 4, 5, 6, 18, 9,45};
int n = sizeof(a) / sizeof(a[0]);
sort(a, a+n);



binarySearch(a,n);

}