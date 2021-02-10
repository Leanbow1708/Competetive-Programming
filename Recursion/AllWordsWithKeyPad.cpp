#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string> keys;
vector<string> res_main;


void fun(vector<string> ans,string s,int n){

    vector<string> res;

    if(n < 0)
    {
        for(int i = 0;i < ans.size();i++)
        {

            //cout<<ans[i];
            res_main.push_back(ans[i]);
        }
        return;

    }

    else{

             string currS = keys[(char)s[n]-'0'];

    for(int i = 0;i < currS.length();i++)
        {
            for(int j = 0;j < ans.size();j++)
            {

                res.push_back(currS[i]+ans[j]);
            }


        }

    }

    fun(res,s,n-1);


}


int main()
{
    keys[1] = "";
    keys[2] = "ABC";
    keys[3] = "DEF";
    keys[4] = "GHI";
    keys[5] = "JKL";
    keys[6] = "MNO";
    keys[7] = "PQRS";
    keys[8] = "TUV";
    keys[9] = "WXYZ";

    string s;
    cin>>s;

    vector<string> v;
        v.push_back("");

  fun(v,s,s.length()-1);
  for(int i = 0;i < res_main.size();i++)
  {
      cout<<res_main[i]<<endl;
  }




    return 0;
}
