#include<bits/stdc++.h>
using namespace std;

const int mx=30;
vector<int>adj[mx];
bool visited[mx];
vector<int>ans;


  void DFS(int s)
  {
    visited[s]=1;
    for(auto v:adj[s])
    {
        if(visited[v]==0)
        {
            DFS(v);
        }
    }
    ans.push_back(s);
  }

int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
         cin>>u>>v;
         adj[u].push_back(v);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        DFS(i);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
         cout<<ans[i]<<" ";
    }
    cout<<endl;
}