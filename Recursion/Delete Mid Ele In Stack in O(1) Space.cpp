#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& s,int mid,int pos){

    if(s.empty() || pos > mid)
        return;
    int x = s.top();
    s.pop();
    insert(s,mid,pos+1);
    if(pos != mid)
    {

        s.push(x);
    }


}


int main()
{

    stack<int> s;

    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    int mid = (n+1)/2;


    insert(s,mid,1);
    for(int i = 0;i < n-1;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }





    return 0;
}
