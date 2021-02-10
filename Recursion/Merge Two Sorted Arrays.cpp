#include<iostream>
using namespace std;

void merge_fun(int* a,int* b,int n,int m){

    int t[m+n];
    int N = m+n;
    int l = 0;
    int r = 0;
    int i =0;
    while(l < n || r < m)
    {
        if(l == n)
        {

            t[i] = b[r];
            r++;
            i++;

        }
        else if(r == m){

                t[i] = a[l];
            l++;
            i++;

        }



       else if(a[l] <= b[r])
        {

            t[i] = a[l];
            l++;
            i++;
        }
        else{
            t[i] = b[r];
            r++;
            i++;
        }

    }

    for(int i = 0;i < N;i++)
    {

        cout<<t[i]<<" ";
    }



}



int main(){

    int a[3] = {1,2,3};
    int b[3] = {2,5,6};
    merge_fun(a,b,3,3);



}
