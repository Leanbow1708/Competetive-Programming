#include<bits/stdc++.h>
using namespace std;

int fun(int n,int k){

    if(n == 1)
    {
        return 0;
    }
        else{

            int x = fun(n-1,(k+1)/2);
            if(x == 1){

                if(k % 2 == 1)
                {

                    return 1;
                }
                else{
                    return 0;
                }

            }
            else{

                if(k % 2 == 1)
                {

                    return 0;
                }
                else{
                    return 1;
                }

            }



        }



}



/*
string replace01(string s){

    if(s.length() == 1)
    {
        if(s[0] == '0')
        {
            return "01";
        }
        else{
            return "10";
        }

    }else{


    char c = s[0];
    string res = replace01(&s[1]);
    if(c == '0')
    {

        res = "01"+res;
    }
    else{
        res = "10"+res;
    }
    return res;



    }


}
*/

int main()
{



    int n;
    int k;
    cin>>n>>k;
    cout<<fun(n,k);


    return 0;
}
