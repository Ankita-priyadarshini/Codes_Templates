#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
typedef long long ll;

const ll mod = 1e9 + 7;
ll n, m;
ll cnt;
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

struct Edge {
    ll u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

void solve(){
    cin >> n >> m;
    vector<Edge> edges(m);

    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(all(edges));
    unionFind uf(n);

    ll mst_cost = 0;
    vector<Edge> mst_edges;

    for(auto &e : edges) {
        if(uf.unionSet(e.u, e.v)) {
            mst_cost += e.w;
            mst_edges.push_back(e);
        }
    }
}

int main() {
	IOS
// 	ll t; cin >> t; while(t--)
	solve();
	return 0;
}