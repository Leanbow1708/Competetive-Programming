#include<bits/stdc++.h>
using namespace std;
/*

Recursive approach

int fun(int* a,int n,int sum){

    if(n == 0)
    {
        return sum;
    }
    else{


        int x = fun(a+1,n-1,sum+a[0]);
        int y = sum;
        int z = fun(a+1,n-1,a[0]);


        return max(x,max(y,z));

    }


}*/

long long fun(long long* a,int n)
{

    long long sum[n];
    long long best = a[0];
    long long curr = a[0];
    if(a[0] < 0)
    {
         curr = 0;
    }
    for(int i = 1;i < n;i++)
    {
     sum[i] = a[i] + curr;
     curr = sum[i];
     best = max(best,curr);
     if(curr < 0)
     {
         curr = 0;
     }
    }
    return best;




}




int main()
{
    int n;
    cin>>n;
    long long a[n];

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    cout<<fun(a,n);

    return 0;
}
