#include<bits/stdc++.h>
using namespace std;

void merge(int* a,int* b,int n,int m)
{
    for(int i = 0;i < n;i++)
    {

        if(a[i] > b[0])
        {
            swap(a[i],b[0]);
            for(int j = 0;j < m-1;j++)
            {

                if(b[j] > b[j+1])
                    swap(b[j],b[j+1]);
                else
                    break;
            }

        }


    }



}


int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < m;i++)
        cin>>b[i];
    merge(a,b,n,m);
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    for(int i = 0;i < m;i++)
        cout<<b[i]<<" ";



    return 0;
}
