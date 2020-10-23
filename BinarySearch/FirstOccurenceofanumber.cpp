#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {

        cin>>a[i];
    }
    int s;
    cin>>s;

    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r)
    {
        int mid  = (l+r)/2;

        if(a[mid] == s)
        {
            if(mid > 0)
            {
                if(a[mid-1] != s)
                {

                    ans = mid;
                    break;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                ans = mid;
                break;
            }

        }
        else{
            if(a[mid] > s)
            {

                r = mid-1;

            }
            else{
                l = mid + 1;
            }
        }





    }
    cout<<ans;





    return 0;
}
