#include<iostream>
using namespace std;



void fun(int* a,int s,int mid,int e){

    while(s < mid)
    {
        if(a[s] < a[mid])
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




void quickSort(int *a,int s,int e){


    if(s >= e)
        return;

    int count = 0;

    for(int i = s+1;i <= e;i++)
    {
        if(a[i] < a[s])
        {
            count++;
        }

    }


    int mid = s+count;
    swap(a[mid],a[s]);
    fun(a,s,mid,e);
    quickSort(a,s,mid-1);
    quickSort(a,mid+1,e);





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
    quickSort(a,0,n-1);
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }



    return 0;
}
