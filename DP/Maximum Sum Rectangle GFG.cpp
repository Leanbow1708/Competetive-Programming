#include<bits/stdc++.h>
using namespace std;

int maxSumSub(int* a,int n)
{

    int sum[n];
    int best = a[0];
    int curr = a[0];
    if(a[0] < 0)
    {
         curr = 0;
    }
    for(int i = 1;i < n;i++)
    {
     sum[i] = a[i] + curr;
     curr = sum[i];
     best = max(best,curr);
     if(curr < 0)
     {
         curr = 0;
     }
    }
    return best;




}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int MAX = INT_MIN;
        int m,n;
        cin>>m>>n;;
        int a[m][n];
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i = m-1;i >= 0;i--)
        {
            int temp[n] = {0};

            for(int j = i;j >= 0;j--)
            {
                for(int k = 0;k < n;k++)
                {

                    temp[k] = temp[k] + a[j][k];
                }
                MAX = max(MAX,maxSumSub(temp,n));


            }


        }

        cout<<MAX<<endl;






    }





    return 0;
}
