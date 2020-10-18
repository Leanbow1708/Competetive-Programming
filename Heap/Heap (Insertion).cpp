
#include<bits/stdc++.h>
using namespace std;


// max heap

void heapify(int i,vector<int> &a,int n){


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

void insert(int i,vector<int> &a){

    int n = a.size();
    int parent = (i-1)/2;
    if(parent >= 0)
    {
        if(a[parent] < a[i])
        {
            swap(a[parent],a[i]);
            insert(parent,a);
        }
    }


}

int main()
{


    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i = (n-2)/2;i >= 0;i--)
    {

        heapify(i,a,n);
    }

    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;

    cout<<"Enter no. of elements you want to add";
    cin>>n;
    cout<<endl;
    while(n--)
    {

        int x;
        cin>>x;
        a.push_back(x);

        int N = a.size();
        int parent = (N-2)/2;
        if(a[parent] < a[N-1] && parent >= 0)
        {
            swap(a[parent],a[N-1]);
            insert(parent,a);

        }
        for(int i = 0;i < N;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;



    }





    return 0;
}
