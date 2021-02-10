#include<bits/stdc++.h>
using namespace std;
long long maxProduct(int *arr, int n) {
	    // code here

	    long long ans = arr[0];

	    long long max_pos = arr[0];
	    long long max_neg = arr[0];
	    for(int i = 1;i < n;i++)
	    {
	        long long x = arr[i];

	        if(arr[i] != 0)
	        {
	            long long a = arr[i]*max_pos;
	            long long b = arr[i]*max_neg;

	            max_neg = min(min(a,b),x);
	            max_pos = max(max(a,b),x);
	            ans = max(ans,max_pos);
	            cout<<ans<<endl;



	        }
	        else{
	            if(i < n-1)
	            {
	                i++;
	            max_pos = arr[i];
	            max_neg = arr[i];
	            }



	        }


	    }

	    ans = max(max_pos,ans);
	    return ans;



	}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    cout<<maxProduct(arr,n);


    return 0;
}
