#include<bits/stdc++.h>
using namespace std;


const int inf=999999;
int  dp[510][510];
int main(){

    int n,m;      
    cin>>n>>m;

    int q;                
    cin>>q;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=inf;
            if(i==j){
                dp[i][j]=0;
            }
        }
    }

    while(m--){
        int u,v;            cin>>u>>v;
        int  w;               cin>>w;
        dp[u][v]=min(w,dp[u][v]);
        dp[v][u]=min(w,dp[v][u]);
    }

    // Floyd-warshall Starts:
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    while(q--){
        int u,v;            cin>>u>>v;
        if(dp[u][v]==inf){
            cout<<-1<<endl;
        }
        else{
            cout<<dp[u][v]<<endl;
        }
    }

    return 0;
}


/*

5 6
1 2 2
1 3 4
1 5 10
5 4 1
3 4 2
2 4 6

*/