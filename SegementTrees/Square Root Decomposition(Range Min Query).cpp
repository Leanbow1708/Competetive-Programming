#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int l = sqrt(n);
    int len = ceil((double)n/l);
    vector<int> v(len);
    int temp_min = INT_MAX;
    int turn = -1;
    for(int i = 0;i < n;i++)
    {


        scanf("%d",&a[i]);
        if(i/l != turn)
        {

            if(turn != -1)
            {

                v[turn] = temp_min;


            }
            turn = i/l;

            temp_min = a[i];
        }
        else{
            temp_min = min(temp_min,a[i]);
        }
    }

      /*  for(int i = 0;i < len;i++)
        {

            cout<<v[i]<<" ";
        }

*/

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        int bl = L/l;
        int br = R/l;

        int ans = INT_MAX;
        if(bl == br)
        {

            for(int i = L;i <= R;i++)
            {

                ans = min(ans,a[i]);
            }
        }



       else{
         for(int i = bl+1;i < br;i++)
        {

            ans = min(ans,v[i]);
        }
        //for block on left query;

        for(int i = L;i < (bl+1)*l;i++)
        {

            ans = min(ans,a[i]);
        }
        for(int i = br*l;i <= R;i++)
        {

            ans = min(ans,a[i]);
        }
       }
        printf("%d\n",ans);





    }



    return 0;
}
