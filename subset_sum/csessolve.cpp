#include<bits/stdc++.h>
using namespace std;


void findsum(vector<int>& v ,int l,int r,unordered_map<int,int>& m, int  aiporjonto_sum,int x)
{
    if(aiporjonto_sum>x)
    {
        return;
    }
    if(l>r || aiporjonto_sum==x)
    {
        m[aiporjonto_sum]++;
        return;
    }
    findsum(v,l+1,r,m,aiporjonto_sum,x); /// leave 
    if(aiporjonto_sum+v[l]<=x)
    {
        findsum(v,l+1,r,m,aiporjonto_sum+v[l],x);  /// take 
    }
}

long long findresult(vector<int>& v, int x)
{
    unordered_map<int,int>freq1;
    freq1.reserve(1<<20);
    findsum(v,0,v.size()/2-1,freq1,0,x);

    unordered_map<int,int>freq2;
    freq2.reserve(1<<20);
    findsum(v,v.size()/2,v.size()-1,freq2,0,x);

    long long ans=0;
    for(auto it:freq1)
    {
        int f2=x-it.first;
        if(freq2.find(f2)!=freq2.end())
        {
            ans += 1ll * (it.second)*(freq2[f2]);
        }
    }
    //cout<<ans<<endl;
    return ans;
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
         int p;
         cin>>p;
         v.push_back(p);
    }
    cout<<findresult(v,x);
    return 0;
}
