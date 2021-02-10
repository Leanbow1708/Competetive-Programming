#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i = 0;i < n;i++)
	        cin>>arr[i];
	    int l = 0;
	    int h = 0;
	    int sum = 0;
	    int ans = INT_MAX;
	    while(1)
	    {
	        if(l > h || (sum <= x && h == n))
	            break;
	       if(sum > x)
	        {

	            ans = min(ans,h-l);
	            sum = sum - arr[l];
	            l++;
	        }
	        else{
	            sum = sum + arr[h];
	            h++;
	        }

	    }
	    cout<<ans<<endl;



	}


	return 0;
}
