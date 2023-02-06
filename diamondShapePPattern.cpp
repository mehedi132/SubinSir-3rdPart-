#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n = 5;
int i,j,k=1;
        for(i=0;i<2*n;i++)
        {
            if(i<n)
            {
                for (j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }
            for (j = 0; j < 2*i+1; j++)
            {
                cout << "*";
            }

            for (j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }
            cout << endl;

            }
            else{

                for (j = 0; j < i-n; j++)
            {
                cout << " ";
            }
            for (j = 0; j < 2*n-k; j++)
            {
                cout << "*";
            }
            k = k + 2;

            for (j = 0; j <i-n; j++)
            {
                cout << " ";
            }
            cout << endl;
            }
            
        }


}