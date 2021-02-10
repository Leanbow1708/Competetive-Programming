#include<bits/stdc++.h>
using namespace std;

set<string> s;

void solve_case(int* a,int n){



    int l = pow(2,n) - 1;
    for(int i = 0;i <= l;i++)
    {
        int x = n,j = n-1,t = i;
        string str = "";
        int flag = 0;
        while(x--)
        {
                char c = (char)(48+a[j]);

            if(t&1  == 1)
            {
                if(flag == 1)
                    str += " ";

                if(x != 0)
                {
                    str += c;

                }
                else{
                    str += c;
                }
            flag = 1;

            }
            t = t>>1;
            j--;


        }


        s.insert(str);

    }


}

void test_case(){

    s.clear();
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    solve_case(a,n);
    for(auto it = s.begin();it != s.end();it++)
    {
        cout<<"("+*it+")";
    }




}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        test_case();
        cout<<endl;

    }



    return 0;
}
