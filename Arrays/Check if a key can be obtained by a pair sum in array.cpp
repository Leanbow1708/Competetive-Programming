#include<bits/stdc++.h>
using namespace std;
bool fun(int* arr,int n,int x)
{
    sort(arr,arr+n);
    int l = 0;
    int h = n-1;
    while(l < h)
    {
        int sum = arr[l]+arr[h];
        if(sum == x) return 1;
        else if(sum > x) h--;
        else l++;
    }
    return 0;


}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    cout<<fun(arr,n,k);

    return 0;
}
