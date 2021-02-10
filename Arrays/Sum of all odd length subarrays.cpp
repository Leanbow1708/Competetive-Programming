#include<bits/stdc++.h>
using namespace std;
int sumOddLengthSubarrays(vector<int>& arr) {


        int n = arr.size();
        int N = n;
        if(N%2 == 0)
            N--;

        int sum = 0;

        for(int len = 1;len <= N;len += 2)
        {
            for(int i = 0;i < n;i++)
            {

                if(i+len <= n)
                for(int j = i;j < i+len;j++)
                {
                    sum += arr[j];
                }

            }
        }
        return sum;

    }
int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin>>arr[i];

    cout<<sumOddLengthSubarrays(arr);



    return 0;
}
