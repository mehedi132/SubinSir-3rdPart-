#include<bits/stdc++.h>
using namespace std;
void pra(int a[], int n)
{
    int i;
    for (i = 0; i < n;i++)
{
    cout<<a[i]<<" ";
}
}

int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int arr[100];
int n, i, j;
cin >> n;
for (i = 0; i < n;i++)
{
    cin >> arr[i];
}

for (i = 1; i < n;i++)
{
    int current =arr[i];
    j = i - 1;
    while(arr[j]>current && j>=0)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = current;
    cout << "step" << i  << ":";
    pra(arr, n);
    cout << endl;
}


}