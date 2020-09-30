#include<bits/stdc++.h>
#define mx 100005
#define mn -200000
using namespace std;




struct Node
{
    public:
    long preVal;
    long preCount;
    long sufVal;
    long sufCount;
    long ans;

    Node(){

        preVal = preCount = sufVal = sufCount = ans = mn;
    }

};
Node tree[4*mx+1];
long a[mx];


Node merge1(Node l,Node r)
{
    Node cur;
    cur.preVal = l.preVal;
    cur.sufVal = r.sufVal;
    cur.preCount = l.preCount;
    cur.sufCount = r.sufCount;
    if(l.preVal == r.preVal)
    {
        cur.preCount = l.preCount + r.preCount;

    }
    if(l.sufVal == r.sufVal)
    {

        cur.sufCount = l.sufCount + r.sufCount;
    }
    cur.ans = max(l.ans,r.ans);
    if(l.sufVal == r.preVal)
    {
        cur.ans = max(cur.ans,l.sufCount+r.preCount);

    }
    return cur;

}

void buildTree(long index,long s,long e){

    if(s == e)
        {

            tree[index].ans = 1;
            tree[index].preCount = 1;
            tree[index].sufCount = 1;
            tree[index].sufVal = a[s];
            tree[index].preVal = a[s];



        }
        else{

           long mid = (s+e)/2;
           buildTree(2*index,s,mid);
           buildTree(2*index+1,mid+1,e);

           tree[index] = merge1(tree[2*index],tree[2*index+1]);

/*
           cout<<s<<" "<<e<<"->"<<endl;
           cout<<"pre val "<<tree[index].preVal<<endl;
           cout<<"pre count "<<tree[index].preCount<<endl;
           cout<<"suf val "<<tree[index].sufVal<<endl;
           cout<<"suf count"<<tree[index].sufCount<<endl;
           cout<<"ans "<<tree[index].ans<<endl<<endl;

*/


        }






}



Node queryRange(long index,long qs,long qe,long s,long e){

    ///No Overlap
    if(qe<s || qs>e)
    {
        Node n;
        return n;
    }
    ///Complete Overlap
    else if(qs<=s && qe>=e)
    {
        return tree[index];

    }
    else{

        long mid = (s+e)/2;
        Node left = queryRange(2*index,qs,qe,s,mid);
        Node right =queryRange(2*index+1,qs,qe,mid+1,e);

        Node n = merge1(left,right);
        return n;



    }

}




int main()
{

    long n,t;
    scanf("%ld%ld",&n,&t);
    for(long i = 0;i < n;i++)
    {
        scanf("%ld",&a[i]);
    }
    buildTree(1,0,n-1);


     long l,r;


    while(t--)
    {
        scanf("%ld%ld",&l,&r);
        Node x = queryRange(1,l-1,r-1,0,n-1);
        printf("%ld\n",x.ans);
    }



    return 0;
}
