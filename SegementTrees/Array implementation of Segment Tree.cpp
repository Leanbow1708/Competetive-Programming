#include<bits/stdc++.h>
using namespace std;

//Update array using lazy propogation


void lazyUpdate(int index,int qs,int qe,int s,int e,int value,int* tree,int* lazy)
{


    if(lazy[index] != 0)
    {

        tree[index] += lazy[index];
        lazy[2*index] += lazy[index];
        lazy[2*index+1] += lazy[index];
        lazy[index] = 0;
    }
    if(qe < s || qs > e)
        return;
    if(s>=qs && e<=qe)
    {

        tree[index] += value;
        if(s != e)
        {

            lazy[2*index] += value;
            lazy[2*index+1] += value;
        }
        return;
    }
    int m = (s+e)/2;
    lazyUpdate(2*index,qs,qe,s,m,value,tree,lazy);
    lazyUpdate(2*index+1,qs,qe,m+1,e,value,tree,lazy);
    tree[index] = min(tree[2*index],tree[2*index+1]);



}
int lazyQuery(int index,int qs,int qe,int s,int e,int* tree,int* lazy){


    if(lazy[index] != 0)
    {

        tree[index] += lazy[index];
        lazy[2*index] += lazy[index];
        lazy[2*index+1] += lazy[index];
        lazy[index] = 0;
    }
     if(qe < s || qs > e)
        return INT_MAX;
         if(s>=qs && e<=qe)
    {
        return tree[index];
    }
    int m = (s+e)/2;
   int left =  lazyQuery(2*index,qs,qe,s,m,tree,lazy);
   int right =  lazyQuery(2*index+1,qs,qe,m+1,e,tree,lazy);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return tree[index];





}






void buildTree(int index,int s,int e,int* tree,int* a){

    if(s == e)
        {
            tree[index] = a[s];
        }
        else{

           int mid = (s+e)/2;
           buildTree(2*index,s,mid,tree,a);
           buildTree(2*index+1,mid+1,e,tree,a);

           tree[index] = min(tree[2*index],tree[2*index+1]);
        }
}

int queryRange(int index,int qs,int qe,int s,int e,int* tree){

    ///No Overlap
    if(qe<s || qs>e)
    {
        return INT_MAX;
    }
    ///Complete Overlap
    else if(qs<=s && qe>=e)
    {
        return tree[index];

    }
    else{

        int mid = (s+e)/2;
        int left = queryRange(2*index,qs,qe,s,mid,tree);
        int right = queryRange(2*index+1,qs,qe,mid+1,e,tree);
        return min(left,right);

    }

}

void rangeQuery(int index,int rs,int re,int value,int s,int e,int* tree)
{
    if(re<s || rs>e)
    {
        return;
    }
    else if(s == e)
    {
        tree[index] += value;
        return;

    }

    int mid = (s+e)/2;
    rangeQuery(2*index,rs,re,value,s,mid,tree);
   rangeQuery(2*index+1,rs,re,value,mid+1,e,tree);
    tree[index] = min(tree[2*index],tree[2*index+1]);



}


void updateOneElement(int* tree,int index,int s,int e,int value,int i)
{

    if(e<index || s>index)
        return;
    else if(s == e)
    {

        tree[i] = value;
        return;
    }
    int mid = (s+e)/2;
    updateOneElement(tree,index,s,mid,value,2*i);
    updateOneElement(tree,index,mid+1,e,value,2*i+1);
    tree[i] = min(tree[2*i],tree[2*i+1]);





}




int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {

        cin>>a[i];
    }

    int* tree = new int[4*n+1];
    int* lazy = new int[4*n+1];

    for(int i = 0;i < 4*n+1;i++)
    {

        tree[i] = INT_MAX;
        lazy[i] = 0;
    }

    buildTree(1,0,n-1,tree,a);

    lazyUpdate(1,0,36
1 3 2 -2 4 56
1 3 2 -2 4 56
1 3 2 -2 4 5,0,n-1,10,tree,lazy);
    cout<<lazyQuery(1,0,5,0,5,tree,lazy);


/*
    for(int i = 0;i < 4*n+1;i++)
    {

        if(tree[i] != INT_MAX)
        {

            cout<<i<<" "<<tree[i]<<endl;
        }
    }
*/



   // cout<<endl<<endl;
    //updateOneElement(tree,3,0,n-1,-6,1);

   /* rangeQuery(1,1,4,3,0,n-1,tree);

    for(int i = 0;i < 4*n+1;i++)
    {

        if(tree[i] != INT_MAX)
        {

            cout<<i<<" "<<tree[i]<<endl;
        }
    }*/


  //  cout<<queryRange(1,0,2,0,n-1,tree);






}
