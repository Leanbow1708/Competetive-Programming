#include<bits/stdc++.h>
using namespace std;


queue<string> q;

void perm(string s){

    if(s.length() == 1)
    {
        q.push(s.substr(0,1));
        return;
    }
    else{

        perm(&s[1]);

        int x = q.size();
        for(int i = 0;i < x;i++)
        {
            string temp = q.front();
            q.pop();
            q.push(s.substr(0,1)+temp);
            q.push(s.substr(0,1)+" "+temp);


        }




    }


}

int main()
{
    string s;
    cin>>s;
    perm(s);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();

    }


    return 0;
}
