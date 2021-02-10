#include<bits/stdc++.h>
#define mx 50005
#define mn -200000
using namespace std;



struct Node
{
    long long prefixSum;
    long long sufixSum;
    long long totalSum;
    long long subArraySum;

    Node(){

        prefixSum = sufixSum = totalSum = subArraySum = mn;
    }

};
Node tree[4*mx+1];
int a[mx];

Node merge1(Node l,Node r)
{
    Node cur;

    cur.prefixSum = max(l.prefixSum,l.totalSum+r.prefixSum);
    cur.sufixSum = max(r.sufixSum,l.sufixSum+r.totalSum);
    cur.totalSum = l.totalSum+r.totalSum;
    cur.subArraySum = max(l.subArraySum,max(r.subArraySum,l.sufixSum+r.prefixSum));
    return cur;


}










void buildTree(int index,int s,int e){

    if(s == e)
        {


            tree[index].prefixSum = a[s];
            tree[index].sufixSum = a[s];
            tree[index].subArraySum = a[s];
            tree[index].totalSum = a[s];

        }
        else{

           int mid = (s+e)/2;
           buildTree(2*index,s,mid);
           buildTree(2*index+1,mid+1,e);

           tree[index] = merge1(tree[2*index],tree[2*index+1]);



        }
}




Node queryRange(int index,int qs,int qe,int s,int e){

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

        int mid = (s+e)/2;
        Node left = queryRange(2*index,qs,qe,s,mid);
        Node right =queryRange(2*index+1,qs,qe,mid+1,e);

        Node n = merge1(left,right);
        return n;



    }

}



void update(int index,int s,int e,int value,int i){

    if(e<i || s>i)
        return;
     else if(s == e)
    {

        tree[index].prefixSum = value;
        tree[index].sufixSum = value;
        tree[index].subArraySum = value;
        tree[index].totalSum = value;

        return;
    }

    int mid = (s+e)/2;
    update(2*index,s,mid,value,i);
    update(2*index+1,mid+1,e,value,i);
    tree[index] = merge1(tree[2*index],tree[2*index+1]);



}


int main()
{
    int n;
    scanf("%d",&n);


    for(int i = 0;i < n;i++)
    {

        scanf("%d",&a[i]);
    }
    buildTree(1,0,n-1);


    int t;
    scanf("%d",&t);
    while(t--)
    {

        int f,l,r;
        scanf("%d%d%d",&f,&l,&r);
        if(f == 1)
        {
            l--;
        r--;
       Node x =  queryRange(1,l,r,0,n-1);

    printf("%lld\n",x.subArraySum);

        }
        else{
            l--;

            update(1,0,n-1,r,l);



        }







    }



/*
    int q;
    scanf("%d",&q);
    while(q--)
    {

        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        r--;
       Node x =  queryRange(1,l,r,0,n-1);

    printf("%lld\n",x.subArraySum);
    }
*/


    return 0;
}
