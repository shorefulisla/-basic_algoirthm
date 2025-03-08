#include<bits/stdc++.h>
using namespace std;

const int mx=2e5+123;
int tree[mx*3],a[mx];

void init(int id,int b,int e)
{
    if(b==e)
    {
        tree[id]=b;
        return;
    }
    int mid=(b+e)/2;
    init(id*2,b,mid);
    init(id*2+1,mid+1,e);

    tree[id]=tree[id*2]+tree[id*2+1];
}

int ask(int id,int b,int e,int i,int j)
{
    if(e<i or b>j)
    {
        return 0;
    }
    if(b>=i and e<=j)
    {
        return tree[id];
    }

    int mid=(b+e)>>1;
    int leftsum=ask(id*2,b,mid,i,j);
    int rightsum=ask(id*2+1,mid+1,e,i,j);
    return leftsum+rightsum;
}
int main()
{
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
     init(1,1,n);
     for(int i=1;i<=15;i++)
     {
        cout<<tree[i]<<" ";
     }

     int ans=ask(1,1,n,3,4);
     cout<<ans<<endl;

     cout<<endl;
}