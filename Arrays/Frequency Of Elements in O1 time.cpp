#include<bits/stdc++.h>
using namespace std;

void frequencycount(vector<int>& arr,int n)
{

   for(int i = 0;i < n;i++)
        arr[i]--;
   for(int i = 0;i < n;i++)
   {
       int x = arr[i]%n;
       arr[x] = arr[x]+n;
   }
   for(int i = 0;i < n;i++)
   {
       arr[i] = (arr[i]/n);

   }
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin>>arr[i];

      frequencycount(arr,n);
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";




    return 0;
}
