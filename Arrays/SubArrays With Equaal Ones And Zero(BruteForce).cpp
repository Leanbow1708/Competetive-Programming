#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin>>v[i];

    int count = 0;
    for(int i = 0;i < n;i++)
    {
        int z = 0;
        int o = 0;
        if(v[i] == 1)
        {
            o++;

        }
        else{
            z++;
        }
        for(int j = i+1;j < n;j++)
        {



            if(v[j] == 1)
        {
            o++;

        }
        else{
            z++;
        }
        if(o == z)
            count++;


        }
    }

cout<<count;

    return 0;
}
