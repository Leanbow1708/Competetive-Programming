#include<bits/stdc++.h>
using namespace std;
vector<string> v;

void perm(string s,int a,int b){

    if(a == 0 && b == 0)
    {
        v.push_back(s);
        return;
    }
    if(a > 0)
    {
     perm(s+"(",a-1,b);
    }

    if(b-1 >= a)
    {
        perm(s+")",a,b-1);
    }




}


void fun(int n){


    int a = n;
    int b = n;
    string s = "(";
    perm(s,a-1,b);


}



int main()
{
    int n;
    cin>>n;
    fun(n);
    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<endl;

    }


    return 0;
}
