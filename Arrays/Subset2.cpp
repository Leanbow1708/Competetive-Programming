#include<bits/stdc++.h>
using namespace std;


vector<int> nums;
int n;

int fun(vector<vector<int>>& ans,int k)
{
    if(k == n-1)
    {
        vector<int> v;
        ans.push_back(v);
        v.push_back(nums[k]);
        ans.push_back(v);
        return 1;
    }
    else{
       int z = fun(ans,k+1);
        if(nums[k] == nums[k+1])
        {
            int K = ans.size();
            for(int i = K-z;i < K;i++)
        {
            vector<int> x = ans[i];
            x.push_back(nums[k]);
            ans.push_back(x);

        }
           return z;



        }
        else{

             int K = ans.size();

        for(int i = 0;i < K;i++)
        {
            vector<int> x = ans[i];
            x.push_back(nums[k]);
            ans.push_back(x);

        }

            return K;
        }





    }


}



  vector<vector<int>> subsetsWithDup(vector<int>& num) {


        sort(num.begin(),num.end());

         nums = num;
        n = num.size();
        vector<vector<int>> v;
        fun(v,0);
        return v;


    }

int main()
{

    cin>>n;
    nums.clear();
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    vector<vector<int>> ans = subsetsWithDup(nums);

    for(int i = 0;i < ans.size();i++)
    {


        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";

        cout<<endl;


    }



    return 0;
}
