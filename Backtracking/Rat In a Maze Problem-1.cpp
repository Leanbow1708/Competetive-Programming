#include<bits/stdc++.h>
using namespace std;

vector<string> res;
int m[100][100];
int vis[100][100];
int n;

bool isValid(int i,int j){

    if(i>=0 && i<n && j>=0 && j<n){
        return 1;
    }
    return 0;

}

void fun(int i,int j,string s)
{
    if(i==n-1 && j==n-1)
    {
      res.push_back(s);
      return;
    }
    vis[i][j] = 1;
    /// now move in all possible directions

    ///D
    if(isValid(i+1,j) && vis[i+1][j]==0 && m[i+1][j]==1)
    {
        fun(i+1,j,s+"D");
    }
    ///U
    if(isValid(i-1,j) && vis[i-1][j]==0 && m[i-1][j]==1)
    {
        fun(i-1,j,s+"U");
    }
    ///L
    if(isValid(i,j-1) && vis[i][j-1]==0 && m[i][j-1]==1)
    {
        fun(i,j-1,s+"L");
    }
    ///R
    if(isValid(i,j+1) && vis[i][j+1]==0 && m[i][j+1]==1)
    {
        fun(i,j+1,s+"R");
    }

    vis[i][j] = 0;



}

int main()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            cin>>m[i][j];
    }

    string s = "";
    fun(0,0,s);
    for(int i = 0;i < res.size();i++)
    {

        cout<<res[i]<<" ";
    }



    return 0;
}
