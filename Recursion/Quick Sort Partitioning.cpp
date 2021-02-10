#include<iostream>
using namespace std;

void fun(int* a,int s,int mid,int e){

    while(s < mid)
    {
        if(a[s] <= a[mid])
        {
            s++;
        }
       else if(a[e] >= a[mid])
        {
            e--;
        }
        else{
            swap(a[s],a[e]);
            s++;
            e--;
        }


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
    fun(a,0,3,n-1);
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }



    return 0;
}
