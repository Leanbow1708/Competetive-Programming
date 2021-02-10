#include<bits/stdc++.h>
using namespace std;

int pt[50000][10];
void buildSparseTable(int n,int l,int* a){

    for(int i = 0;i < n;i++)
    {
        pt[i][0] = a[i];
    }
    for(int j = 1;j <= l;j++)
    {
        int p = pow(2,j-1);
        int p1 = p*2 - 1;
        for(int i = 0;i+p1 < n;i++)
        {

        int x1 = pt[i][j-1];
        int x2 = pt[i+p][j-1];
        pt[i][j] = min(x1,x2);

        }


    }
    /*
    for(int i = 0;i < n;i++)
    {

        for(int j = 0;j <= l;j++)
        {
            int p = pow(2,j-1);
        int p1 = p*2 - 1;
        if(i+p1 < n)
            printf("%d ",pt[i][j]);
        }
            printf("\n");

    }*/









}

int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l = log2(n);
    l++;
    buildSparseTable(n,l,a);

    int t;
    scanf("%d",&t);
    while(t--)
    {

        int L,R;
    scanf("%d%d",&L,&R);
    l = R-L+1;
    int temp_min = INT_MAX;
    int k = l;
    int x = log2(k);
    int x1 = x;
    int y = pow(2,x1);

    while(k > 0)
    {


        temp_min = min(temp_min,pt[L][x]);
        k = k - y;
        x1 = log2(k);
        y = pow(2,x1);
        L = L + y;

    }
    printf("%d\n",temp_min);

    }









}
