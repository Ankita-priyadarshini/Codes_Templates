#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;

//------------------------------------------------------CODE HERE----------------------------------------------------------------

const int N = 3e5 + 1, M = 20;
vector<vector<pair<int, int>>> adj(N);
int dep[N];
pair<int, int> Par[N][M];

void dfs(int cur, int par, int weight) {
    dep[cur] = dep[par] + 1;
    Par[cur][0] = {par, weight};  
    
    for(int i = 1; i < M; i++) {
        int prev = Par[cur][i - 1].first;
        Par[cur][i] = {Par[prev][i - 1].first, min(Par[cur][i - 1].second, Par[prev][i - 1].second)};
    }

    for (auto it : adj[cur]) {
        int nxt = it.first, w = it.second;
        if (nxt != par) dfs(nxt, cur, w);
    }
}

int minDepth(int u, int v) {
    if (u == v) return 0;
    if (dep[u] < dep[v]) swap(u, v);
    
    int diff = dep[u] - dep[v], mini = LLONG_MAX;
    
    for (int i = M - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            mini = min(mini, Par[u][i].second);
            u = Par[u][i].first;
        }
    }

    if (u == v) return mini;

    for (int i = M - 1; i >= 0; i--) {
        if (Par[u][i].first != Par[v][i].first) {
            mini = min({mini, Par[u][i].second, Par[v][i].second});
            u = Par[u][i].first;
            v = Par[v][i].first;
        }
    }
    
    return min({mini, Par[u][0].second, Par[v][0].second});
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    
    dfs(1, 0, LLONG_MAX);
    
    int q; cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << minDepth(u, v) << "\n";
    }
}

signed main() {
    IOS
    solve();
    return 0;
}