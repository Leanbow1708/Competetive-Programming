#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void fun(string s){

    if(s.length() == 1)
    {


        v.push_back(s.substr(0,1));
        return;
    }
    else{


        fun(&s[1]);

       int x = v.size();
      // cout<<x;
       for(int i = 0;i < x;i++)
       {
           v.push_back(s[0]+v[i]);

       }
       v.push_back(s.substr(0,1));


    }

}



int main()
{
    string s;
   cin>>s;







    fun(s);
    reverse(v.begin(),v.end());
    for(auto it  = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }



    return 0;
}
