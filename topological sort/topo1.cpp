#include <bits/stdc++.h>
using namespace std;

const int mx=30;
vector<int> adj[mx];
vector<int> order;
vector<int> inDegree;


void Toposort(int n){
   queue<int> q;
   for(int i=1;i<=n;i++){
      if(inDegree[i]==0){
         q.push(i);
      }
   }

   while(!q.empty()){
      int curr=q.front();

      q.pop();
      order.push_back(curr);

      for(auto i:adj[curr]){
         inDegree[i]--;
         if(inDegree[i]==0){
            q.push(i);
         }
      }
   }
}


int main(){
     int n,m;       
     cin>>n>>m;

   for(int i=0;i<=n;i++){
      adj[i].clear();
   }

   inDegree.assign(n+2,0);

   while(m--){
      int u,v;          cin>>u>>v;

      adj[u].push_back(v);
      inDegree[v]++;
   }

   Toposort(n);

   for(auto i:order){
      cout<<i<<" ";
   }
   cout<<endl;

   return 0;
}