#include<bits/stdc++.h>
using namespace std;


// max heap

void heapify(int i,int* a,int n){


    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp = i;
    if(left < n)
    {
        if(a[left] > a[temp])
        {
            temp = left;
        }
    }
    if(right < n)
    {
        if(a[right] > a[temp])
        {
            temp = right;
        }
    }
    if(temp != i)
    {
        swap(a[temp],a[i]);
        heapify(temp,a,n);
    }


}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    for(int i = (n-2)/2;i >= 0;i--)
    {

        heapify(i,a,n);
    }

    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }





    return 0;
}
