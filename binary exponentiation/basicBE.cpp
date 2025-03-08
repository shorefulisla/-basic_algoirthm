#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int BE(int x,int y)
{
    int res=1;
    while (y>0)
    {
       if(y%2==1)
       {
         res*=x;
         res%=mod;
       }
       x=(x*x)%mod;
       y/=2;
    }
    return res;   
}
int main()
{
    // find pow(x,y);
    int x,y;
    cin>>x>>y;
    cout<<BE(x,y)<<endl;
    
}
