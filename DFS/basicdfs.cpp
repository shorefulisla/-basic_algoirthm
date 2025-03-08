#include <bits/stdc++.h>
using namespace std;

const int mx=30;
vector<int>adj[mx];
bool visited[mx];

void DFS(int source)
{
    visited[source]=1;
    for(auto node:adj[source])
    {
        if(!visited[node])
        {
             DFS(node);
        }
    }
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
       adj[v].push_back(u);
    }
    DFS(1);

    for(int i=1;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<endl;
}