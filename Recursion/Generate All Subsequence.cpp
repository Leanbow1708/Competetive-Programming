#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void fun(string s){

    if(s.size() == 0)
    {
    v.push_back("");
    return;
    }
    else{

        fun(s.substr(1));
        int n = v.size();
        for(int i = 0;i < n;i++)
        {
            string t = s[0]+v[i];
            v.push_back(t);


        }



    }

}



int main()
{
    string s;
    cin>>s;

    fun(s);

    cout<<v.size()<<endl;
    for(auto it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl;
    }


    return 0;
}
