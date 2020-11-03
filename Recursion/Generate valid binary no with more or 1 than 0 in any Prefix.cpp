#include<bits/stdc++.h>
using namespace std;
vector<string> v;


void perm(string s,int n,int a,int b){

    if(n == 0){
        v.push_back(s);
        return;
    }
    perm(s+"1",n-1,a+1,b);
    if(a > b){
        perm(s+"0",n-1,a,b+1);
    }


}

int main(){

    int n;
    cin>>n;
    string s = "";
    int a = 0;///1s
    int b = 0;///0s
    perm(s,n,a,b);

    for(int i = 0;i < v.size();i++)
    {
        cout<<v[i]<<endl;

    }



}
