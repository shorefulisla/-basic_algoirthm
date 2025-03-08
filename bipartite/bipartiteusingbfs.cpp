#include<bits/stdc++.h>
using namespace std;

bool BFS(int n,vector<int>adj[])
{
    vector<int>color(n,-1);/// initially sokol node er modde "-1" mane holo unvisited ok;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
         if(color[i]==-1)
         {
            color[i]=0;
            q.push(i);
            while (!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto v:adj[u])
                {
                    if(color[v]==-1)
                    {
                        color[v]=1-color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u])
                    {
                        return false; /// jodi adjacent kono node er color same hoi taile bipartite hobe nah ;
                    }
                }
            }
            
         }
    }
    return true; //// succesfull jodi sobgula ke color korte pari taile rteurn yes korbe or possible hobe ;
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector<int>adj[node];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(BFS(node,adj))
    {
        cout<<"yes bipartite "<<endl;
    }
    else 
    {
        cout<<" no not bipartite"<<endl;
    }
}