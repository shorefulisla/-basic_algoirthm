#include<bits/stdc++.h>
using namespace std;

const int mx=1000;
int a[mx];
int tree[mx];

int read(int idx)
{
    int sm=0;
    while (idx>0)
    {
        sm+=tree[idx];
        idx -=(idx & -idx);
    }
    return sm;
}

void update(int idx,int val,int sz)
{
    while (idx<=sz)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
    
}
void print(int a[],int sz)
{
    for(int i=1;i<=sz;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         update(i,a[i],n);
     }
     print(a,n);
     cout<<endl;
     print(tree,n);
     cout<<endl;
     update(4,3,n);
     print(tree,n);
     return 0;
}