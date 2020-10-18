#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    int key = 0;
 int j;
 for(int i = 1;i < n;i++)
 {

     key = a[i];
     for(j = i-1;j >= 0;j--)
     {
         if(a[j] > key)
         {
             a[j+1] = a[j];
         }
         else{
             break;
         }
     }
     a[j+1] = key;


 }

 for(int i = 0;i < n;i++)
 {
     cout<<a[i]<<" ";
 }





}
