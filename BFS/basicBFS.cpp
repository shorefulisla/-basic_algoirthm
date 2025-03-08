#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+123;
vector<int>adj[mx];
int lev[mx];
int par[mx];

void BFS(int s)
{
  for(int i=0;i<mx;i++)
  {
     lev[i]=-1;

  }
  queue<int>q;
  q.push(s);
  lev[s]=0;
  
  while (!q.empty())
  {
     int u=q.front();
     q.pop();
     for(auto v:adj[u])
     {
       if(lev[v]==-1)
       {
         lev[v]=lev[u]+1;
         par[v]=u;
         q.push(v);
       }
     }
  }
  
}
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
   }
   BFS(1);
}