#include<bits/stdc++.h>
using namespace std;
vector<string> res;


int atoi(string s){

    int res = 0;
    int flag = 0;

    for(int i = 0;i < s.size();i++)
    {

        if(s[i] == '-' && i == 0)
        {
            flag = 1;
            continue;

        }

        int x = s[i] - '0';
        if(x >=0 && x <= 9)
        {

            res = res*10 +x;
        }
        else
        return -1;
  }
    if(flag == 1)
        res = -1*res;
    return res;

}

bool isValid(string s){


    int n = s.size();
    if(n == 0)
        return 0;
    if(n > 1 && s[0] == '0')
        return 0;
    int x = atoi(s);
    if(x>=0 && x<=255)
        return 1;

    return 0;
}
void fun(string ans,int count,string s)
{
    int n = s.size();

    if(count == 4 && n == 0)
    {
        res.push_back(ans);
        return;
    }
    if(count == 4 && n > 0)
        return;

    if(count < 4)
    {

        for(int i = 0;i < n;i++)
        {

            string a = s.substr(0,i+1);
            if(isValid(a))
            {

               fun(ans+"."+a,count+1,&s[i+1]);

            }



        }



    }




}


void solve(){

    string s;
    cin>>s;

    int n = s.size();

    for(int i = 0;i < n;i++)
    {

        string ans = s.substr(0,i+1);
        if(isValid(ans))
        fun(ans,1,&s[i+1]);
    }
}


int main()
{
    solve();
    for(int i = 0;i < res.size();i++)
        cout<<res[i]<<endl;



    return 0;
}
