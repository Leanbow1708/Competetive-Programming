#include<iostream>
using namespace std;


void fun(string &s,int l,int h){



    if(l+1 == h){
        return;
    }
    else{

        if(s[l] == s[l+1])
        {
            int i;
            for( i = l+1;i < h;i++)
            {
                s[i-1] = s[i];

            }
            s[i-1] = '\0';
            fun(s,l,h-1);

        }
        else{
            fun(s,l+1,h);
        }

    }


}

int main()
{


    string s;
    cin>>s;
    fun(s,0,s.length());
    cout<<s;



    return 0;
}
