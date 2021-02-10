#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> arr,int a,int b)
{
    int pos_a=0;
    int pos_b=0;

    int n = arr.size();
    int i =0;
    int j = 0;
    while(j < n)
    {
        if(arr[j] < a)
        {
            pos_a++;
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i],arr[pos_a]);
    i = n-1;j = n-1;
    while(j >= 0)
    {

        if(arr[j] > b)
        {
            pos_b++;
            swap(arr[i],arr[j]);
            i--;
        }
        j--;

    }
    swap(arr[i],arr[n-1-pos_b]);
    return arr;




}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    vector<int> ans = fun(arr,a,b);
    for(int i = 0;i < n;i++)
        cout<<ans[i]<<" ";



    return 0;
}
