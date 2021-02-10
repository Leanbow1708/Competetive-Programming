#include<bits/stdc++.h>
using namespace std;

int n = 4;
int vis[4][4];
int dis[4][4];


bool isValid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n && vis[i][j]==0)
        return 1;
    return 0;



}

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};




void bfs(int i1,int j){

    queue<pair<int,int>> q;
    q.push({i1,j});
    dis[i1][j] = 0;
    vis[i1][j] = 1;


    while(!q.empty())
    {

        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i = 0;i < 4;i++)
        {
            int dx = nx+di[i];
            int dy = ny+dj[i];
            if(isValid(dx,dy))
            {
                dis[dx][dy] = dis[nx][ny] + 1;
                q.push({dx,dy});
                vis[dx][dy] = 1;
            }

        }



    }




}


int main()
{

    bfs(1,2);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

