//In the name of ALLAH
//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;
#define int long long int

#define pb push_back
#define endl '\n'
#define mod 1000000007
 
const double eps = 1e-9;
const int inf = 2000000000;
const int infl = 9000000000000000000;
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


signed main()
{
    optimize();

    int TC;
    cin>>TC;
    while (TC--)
    {
       int n;
       cin>>n;
       vector<int>a(n+2),b(n+2),c(n+2),d(n+2),ans(n+2);
       for(int i=1;i<=n;i++)
       {
         cin>>a[i];
       }
       for(int i=1;i<=n;i++)
       {
         cin>>b[i];
         c[i]=c[i-1]+b[i];
       }

       for(int i=1;i<=n;i++)
       {
          int  pos=upper_bound(c.begin()+i,c.begin()+n+1,a[i]+c[i-1])-c.begin();
          d[i]++;
          d[pos]--;
          ans[pos]+= a[i]-(c[pos-1]-c[i-1]);
          d[i]+=d[i-1];
          ans[i]+=(d[i]*b[i]);
       }

       for(int i=1;i<=n;i++)
       {
          cout<<ans[i]<<" ";
       }
       cout<<endl;
    }  
}