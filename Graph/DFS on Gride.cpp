#include<bits/stdc++.h>
using namespace std;

int n = 4;
int vis[4][4];


bool isValid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n && vis[i][j]==0)
        return 1;
    return 0;



}

int del_i[] = {-1,1,0,0};
int del_j[] = {0,0,-1,1};

void dfs2(int i,int j)
{
    vis[i][j] = 1;
    cout<<i<<" "<<j<<endl;

    for(int k = 0;k < 4;k++)
    {
        if(isValid(i+del_i[k],j+del_j[k]))
            dfs2(i+del_i[k],j+del_j[k]);
    }


}


void dfs(int i,int j){

    cout<<i<<" "<<j<<endl;
    vis[i][j] = 1;

    ///move up
    ///but first check if there is a valid cell and it is not traversed previously
    if(isValid(i-1,j))
        dfs(i-1,j);
    ///move down
    if(isValid(i+1,j))
        dfs(i+1,j);
    ///move left
    if(isValid(i,j-1))
        dfs(i,j-1);
    ///move right
    if(isValid(i,j+1))
        dfs(i,j+1);


}


int main()
{

    dfs2(0,0);


    return 0;
}
