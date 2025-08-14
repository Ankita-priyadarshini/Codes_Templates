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

void dfs(int i, vector<vector<int>>& edges, int parent, vector<int>& distNodes){
    if(parent == -1) distNodes[i] = 0;
    else distNodes[i] = distNodes[parent] + 1;
    
    for(auto it : edges[i]){
        if(it != parent){
            dfs(it, edges, i, distNodes);
        }
    }
}

int farthest(int n, vector<int>& dist){
    int y = 1;
    for(int i = 1; i < n; i++){
        if(dist[i] > dist[y]) y = i;
    }
    return y;
}

void solve() {
    int n; cin >> n;
    
    vector<vector<int>> edges(n + 1, vector<int>());
    
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    vector<int> distNodes(n + 1, 0);
    
    int x = getRandomNumber(1, n);
    
    dfs(x, edges, -1, distNodes);
    int y = farthest(n + 1, distNodes);
    
    fill(distNodes.begin(), distNodes.end(), 0);

    dfs(y, edges, -1, distNodes);
    int z = farthest(n + 1, distNodes);
    
    cout << distNodes[z] << "\n";
}

signed main() {
    IOS
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}
