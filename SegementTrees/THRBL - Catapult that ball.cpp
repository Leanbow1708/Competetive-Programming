#include<bits/stdc++.h>
using namespace std;

int pt[50005][100];
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
        pt[i][j] = max(x1,x2);

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

    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l = log2(n);
    l++;
    buildSparseTable(n,l,a);

    int t = m;
    int count = 0;

    while(t--)
    {

        int L,R;

    scanf("%d%d",&L,&R);
    if(L == R)
    {

        count++;
    }
    else{
        L--;R--;R--;
    int L1 = L;
    l = R-L+1;
    int temp_max = INT_MIN;
    int k = l;
    int x = log2(k);
    int x1 = x;
    int y = pow(2,x1);


    while(k > 0)
    {


        temp_max = max(temp_max,pt[L][x]);
        k = k - y;
        x1 = log2(k);
        y = pow(2,x1);
        L = L + y;

    }



    if(temp_max <= a[L1])
    {


        count++;
    }
    }



    }
    printf("%d",count);









}
