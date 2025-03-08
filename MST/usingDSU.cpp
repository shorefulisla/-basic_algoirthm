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
        return parent[x]==x?x:parent[x]=find_root(parent[x]);
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
            return false;
        }
    }
}DSU;



struct EDGE{
	int u;
	int v;
	int  w;
};

bool cond(EDGE a, EDGE b){
	return (a.w<b.w);
}

vector<int> adj[N];

int main(){
	
	int n,m;				cin>>n>>m;

	vector<EDGE> edgeList(m);
	for(int i=0;i<m;i++){
		cin>>edgeList[i].u>>edgeList[i].v>>edgeList[i].w;
	}

	DSU.init(n);

	sort(edgeList.begin(),edgeList.end(),cond);

	int ans=0;
	int connected=0;
	for(int i=0;i<m;i++){
		int u=edgeList[i].u;
		int v=edgeList[i].v;
		int   w=edgeList[i].w;

		if(DSU.unite(u,v)){
			ans+=w;
			adj[u].push_back(v);
			adj[v].push_back(u);
			connected++;
		}
	}

	if(connected!=n-1){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<ans<<endl;
	}


	return 0;
}