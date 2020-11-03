#include<bits/stdc++.h>
using namespace std;

queue<string> q;

void fun(string s){

    if(s.length() == 1)
    {
        char c = '-';
        if(s[0] < 97){
            c = '+';
        }
            q.push(s.substr(0,1));
        if(c == '+')
        {
            char x = char(s[0]+32);
            string t = string(1,x);
            q.push(t);
        }else{
         char x = char(s[0]-32);
            string t = string(1,x);
            q.push(t);
        }



    }
    else{

        fun(&s[1]);

        int n = q.size();

        for(int i = 0;i < n;i++)
        {
            string temp = q.front();
            q.pop();
             char c = '-';
        if(s[0] < 97){
            c = '+';
        }
            q.push(s.substr(0,1)+temp);
        if(c == '+')
        {
            char x = char(s[0]+32);
            string t = string(1,x);
            q.push(t+temp);
        }else{
          char x = char(s[0]-32);
            string t = string(1,x);
            q.push(t+temp);
        }

        }





    }





}




int main()
{
    string s;
    cin>>s;
    fun(s);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();

    }

    return 0;
}
