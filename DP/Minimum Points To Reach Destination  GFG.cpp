#include<iostream>
using namespace std;
 int v[100][100];

int fun(int n,int m){

    int dp[n][m] ;
    int c = m-1;
    dp[n-1][m-1] = 0;
    if(v[n-1][m-1] < 0)
    {

        dp[n-1][m-1] = -1*v[n-1][m-1];
    }

    for(int i = n-2;i >= 0;i--)
    {
        int temp = dp[i+1][c];
        if(temp == -1)
            temp = 0;

        if(v[i][c] < 0)
        {
            dp[i][c] = temp + -1*v[i][c];
        }
        else{
          int res = temp - v[i][c];
            if(res >= 0)
            {
                dp[i][c] = res;

            }
            else{
                dp[i][c] = -1;
            }
        }
    }
    int r = n-1;
    for(int j = m-2; j >= 0;j--)
    {
         int temp = dp[r][j+1];
        if(temp == -1)
            temp = 0;
        if(v[r][j] < 0)
        {

            dp[r][j] = temp + -1*v[r][j];
        }
        else{
             int res = temp - v[r][j];
            if(res >= 0)
            {
                dp[r][j] = res;

            }
            else{
                dp[r][j] = -1;
            }
        }

    }


    for(int i = n-2;i >= 0;i--)
    {

        for(int j = m-2;j >= 0;j--)
        {
            int ans1,ans2;
            //right
            int temp = dp[i][j+1];
            if(temp == -1)
            {
                temp = 0;
            }
            if(v[i][j] < 0)
            {
                ans1 = temp + -1*v[i][j];
            }
            else{
                int res = temp - v[i][j];
                if(res >= 0)
                {
                    ans1 = res;

                }
                else{
                    ans1 = -1;
                }


            }


            //down
             temp = dp[i+1][j];
            if(temp == -1)
            {
                temp = 0;
            }
            if(v[i][j] < 0)
            {
                ans2 = temp + -1*v[i][j];
            }
            else{
                int res = temp - v[i][j];
                if(res >= 0)
                {
                    ans2 = res;

                }
                else{
                    ans2 = -1;
                }


            }


            dp[i][j] = min(ans1,ans2);



        }
    }





if(dp[0][0] == -1)
{

    return 1;
}
else{
    return dp[0][0]+1;
}


}


int main()
{

    int n,m;
    cin>>n>>m;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin>>v[i][j];
        }
    }


    cout<<fun(n,m);




    return 0;
}
