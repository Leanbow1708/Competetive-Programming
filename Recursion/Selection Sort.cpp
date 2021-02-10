#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    //selection sort
    for(int i = 0;i < n-1;i++)
    {
        int idx = i;
        for(int j = i+1;j < n;j++)
        {

            if(a[j] < a[idx])
            {
                idx = j;
            }
        }
        swap(a[i],a[idx]);
    }
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";

    }







}
