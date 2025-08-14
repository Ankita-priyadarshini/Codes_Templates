#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
typedef long long ll;

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};

void solve(){
    int n, m; cin >> n >> m;
    int s, e, d; cin >> s >> e >> d;
    
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> distFromEnemy(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, e});
    distFromEnemy[e] = 0;
    
    while(!pq.empty()){
        int curr = pq.top().first;
        int u = pq.top().second;
        
        pq.pop();
        
        if(curr > distFromEnemy[u]) continue;
        
        for(auto &it : adj[u]){
            int v = it.first;
            int wt = it.second;
            
            if(wt + curr < distFromEnemy[v]){
                distFromEnemy[v] = wt + curr;
                pq.push({distFromEnemy[v], v});
            }
        }
    }
    
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    
    p.push({0, s});
    dist[s] = 0;
    
    while(!p.empty()){
        int curr = p.top().first;
        int u = p.top().second;
        
        p.pop();
        
        if(u == d){
            cout << "YES\n";
            return;
        }
        
        for(auto &it : adj[u]){
            int v = it.first;
            int wt = it.second;
            
            if(wt + curr < distFromEnemy[v] && wt + curr < dist[v]){
                dist[v] = wt + curr;
                p.push({dist[v], v});
            }
        }
    }
    
    cout << "NO\n";
}

int main() {
	IOS
// 	ll t; cin >> t; while(t--)
	solve();
	return 0;
}