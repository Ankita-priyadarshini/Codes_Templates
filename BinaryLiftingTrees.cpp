#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;

int getRandomNumber(int a, int b){
    return uniform_int_distribution<int>(a, b)(rng);
}

//--------------------------------------------------------CODE HERE --------------------------------------------------------

const int N = 2e5 + 1, M = 20;
vector<int> adj[N];
int dep[N], Par[N][M];

void dfs(int cur, int par){
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for(int i = 1; i < M; i++) Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    for(auto it : adj[cur]) if(it != par) dfs(it, cur);
}

int kthParent(int u, int k){
    for(int i = M - 1; i >= 0; i--){
        if((1 << i) & k) u = Par[u][i];
    }
    return u;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }
    
    dfs(1, 0);
    
    while(q--){
        int u, v;
        cin >> u >> v;
        
        int parent = kthParent(u, v);
        cout << (parent == 0 ? -1 : parent) << "\n";
    }
}

signed main() {
    IOS
    // int t; cin >> t; while (t--) 
    solve();
    return 0;
}
