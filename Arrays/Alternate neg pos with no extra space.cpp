#include<bits/stdc++.h>
using namespace std;

void rotate(int* arr,int l,int r)
{

    for(int i = r ;i > l;i--)
        arr[i] = arr[i-1];
}


void rearrange(int* arr,int n)
{
    int l = 1;
    for(l = 1;l < n;l++)
    {
        int a = arr[l];
        int b = arr[l-1];
        if(a == 0)
            a = 1;
        if(b == 0)
            b = 1;
        if(a*b > 0)
        {
            for(int r = l+1;r < n;r++)
            {
                int c = arr[r];
                if(c == 0)
                    c = 1;
                if(a*c < 0)
                {
                    int temp = arr[r];
                    rotate(arr,l,r);
                    arr[l] = temp;

                    break;
                }

            }
        }


    }



}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    rearrange(arr,n);
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";



    return 0;
}
