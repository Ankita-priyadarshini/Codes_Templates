#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
typedef long long ll;

const ll mod = 1e9 + 7;
ll n, m, cnt;
class unionFind{
    // private: 
    public:
        vector<ll> par, rank, sz; 
        unionFind(ll n){
            rank.assign(n + 1, 0);
            par.resize(n + 1);
            sz.assign(n + 1, 1);
            iota(all(par), 0);
            cnt = n;
        }

        ll findSet(ll i){
            return (par[i] == i) ? i : par[i] = findSet(par[i]);
        }

        bool isSameSet(ll i, ll j){
            return findSet(i) == findSet(j);
        }
        
        ll sizeOf(ll i){
            return sz[findSet(i)];
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                cnt--;
                ll x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) {
                    par[y] = x;
                    sz[x] += sz[y];
                } else {
                    par[x] = y;
                    sz[y] += sz[x];
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

void solve(){
    cin >> n >> m;
    
    vector<vector<pair<ll, ll>>> edges(n + 1);
    for(int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }
    
    vector<vector<ll>> mst;
    vector<ll> vis(n + 1), minCost(n + 1, LLONG_MAX);
    
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    
    minCost[1] = 0;
    pq.push({0, 1, -1});
    
    while(!pq.empty()){
        auto [cost, u, p] = pq.top();
        pq.pop();
        
        if(vis[u]) continue;
        vis[u] = 1;
        
        if(p != -1) mst.push_back({p, u, cost});
        
        for(auto [v, wt] : edges[u]){
            if(!vis[v] && minCost[v] > wt){
                minCost[v] = wt;
                pq.push({wt, v, u});
            }
        }
    }
    
    // O(V + ElogV)
    
    // Kruskals -> O(V + ElogE)
}

int main() {
	IOS
// 	ll t; cin >> t; while(t--)
	solve();
	return 0;
}