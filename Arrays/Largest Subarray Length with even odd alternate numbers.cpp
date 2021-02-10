#include<bits/stdc++.h>
using namespace std;

int fun(int *a,int n)
{
    int max_len = 1;
    int curr_len = 1;
    int pre,next;

    for(int i = 0;i < n-1;i++)
    {
        if(i == 0)
        {

            pre = a[i]%2;
            next = a[i+1]%2;
        }
        else
            next = a[i+1]%2;
        if(pre != next)
        {
            curr_len++;

        }else{
        max_len = max(max_len,curr_len);
        curr_len = 1;

        }

        pre = next;



    }
            max_len = max(max_len,curr_len);

    return max_len;

}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    int l = fun(a,n);
    cout<<l;



    return 0;
}
