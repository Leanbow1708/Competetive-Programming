#include<iostream>
using namespace std;

void mergeArray(int* a,int s1,int e1,int s2,int e2){

    int n = e2 - s1 + 1;
    int t[n];

    int l = s1;
    int r = s2;
    int i =0;
    while(l <= e1  || r <= e2)
    {
        if(l == e1+1)
        {

            t[i] = a[r];
            r++;
            i++;

        }
        else if(r == e2+1){

            t[i] = a[l];
            l++;
            i++;

        }



       else if(a[l] <= a[r])
        {

            t[i] = a[l];
            l++;
            i++;
        }
        else{
            t[i] = a[r];
            r++;
            i++;
        }

    }

    for(int i = 0;i < n;i++)
    {
        a[s1+i] = t[i];

    }




}



void mergeSort(int *a,int s,int e){

    if(s == e)
    {

        return ;
    }
    else{


        int mid = (s+e)/2;
        mergeSort(a,s,mid);
        mergeSort(a,mid+1,e);
        mergeArray(a,s,mid,mid+1,e);



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

    mergeSort(a,0,n-1);
    for(int i = 0;i < n;i++)
    {

        cout<<a[i]<<" ";
    }





    return 0;
}
