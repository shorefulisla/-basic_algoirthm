#include<bits/stdc++.h>
using namespace std;

const int inf=9999999;
const int mx = 1e5+123;
vector<pair<int,int>> adj[mx];
int  dist[mx];

void dijkstra ( int s, int n )
{
    for ( int i = 0; i <= n; i++ ) dist[i] = inf; /// initilization
    dist[s] = 0; /// initilizing source distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push ( { 0, s } ); /// pushing source in queue

    while ( !pq.empty() ) {
        int u = pq.top().second;
        int  curD = pq.top().first;
        pq.pop();

        if ( dist[u] < curD ) continue; // important

        for ( auto p : adj[u] ) {
            int v = p.first;
            int w = p.second;
            if ( curD + w < dist[v] ) { // relax operation
                dist[v] = curD + w;
                pq.push ( { dist[v], v } );
            }
        }
    }

}

int main()
{
	
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back ( { v, w } );
        adj[v].push_back ( { u, w } );
    }

    dijkstra ( 1, n );

    for ( int i = 1; i <= n; i++ ) cout << dist[i] << " ";
    cout << endl;

	return 0;
}

/*

5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5


*/