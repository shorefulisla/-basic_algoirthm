#include<bits/stdc++.h>
using namespace std;

const int N=30;
struct Disjoint_Set_Union{
    int parent[N],child[N];
    void init(int n){
        for(int i=0;i<=n;i++){
            parent[i]=i;
            child[i]=1;
        }
    }
    int find_root(int x){
        if(x==parent[x]){
            return x;
        }

        return find_root(parent[x]);
    }
    bool unite(int u,int v){
        int root_u=find_root(u);
        int root_v=find_root(v);
        if(root_u!=root_v){
            if(child[root_u]<child[root_v]){
                swap(root_u,root_v);
            }
            parent[root_v]=parent[root_u];
            child[root_u]+=child[root_v];
            return true;
        }
        else{
            return false; // No new connection created
        }
    }
}DSU;


int main(){

    int n,q;   
    cin>>n>>q;
    
    int cnt=n;

    DSU.init(n);

    while(q--){
        int u,v;
        cin>>u>>v;
        cnt-=(DSU.unite(u,v));
        cout<<cnt<<endl;
    }
    return 0; 
}