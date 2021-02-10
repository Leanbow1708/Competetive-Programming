#include <bits/stdc++.h>
using namespace std;

void test_case()
{

    int n,m,k;
    cin>>n>>m>>k;
    int arr1[n],arr2[m];
    unordered_map<int,int> um1;
    unordered_map<int,int> um2;
    int r_min = INT_MAX;
    int r_max = INT_MIN;

    for(int i = 0;i < n;i++)
        {
            cin>>arr1[i];
            um1[arr1[i]] = 1;
            r_min = min(r_min,arr1[i]);
            r_max = max(r_max,arr1[i]);

        }
    for(int i = 0;i < m;i++)
        {
            cin>>arr2[i];
            um2[arr2[i]] = 1;
        }

        int flag = 0;
        for(int i = r_min;i <= r_max;i++)
        {
            if(um1.find(i) != um1.end())
            {
                int left = k - i;
                if(um2.find(left) != um2.end())
                    {
                        if(flag == 1)
                            cout<<","<<" ";
                        cout<<i<<" "<<left;
                        flag = 1;
                    }
            }


        }

        if(flag == 0)
            cout<<"-1";





}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    test_case();
	    cout<<endl;
	}



	return 0;
}
