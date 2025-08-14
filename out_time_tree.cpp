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

// ------------------------------------------------------------------ code out --------------------------------------------------------------------------------


vector<int> inTime(1e6), outTime(1e6);
int globalTime = 0;

void dfs(int i, vector<vector<int>>& edges, int parent){
    globalTime++;
    inTime[i] = globalTime;
    for(auto it : edges[i]){
        if(it != parent) dfs(it, edges, i);
    }
    globalTime++;
    outTime[i] = globalTime;
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
    
    dfs(1, edges, -1);
    
    for(int i = 1; i <= n; i++){
        cout << inTime[i] << " ";
    }
    
    cout << "\n";
    
    for(int i = 1; i <= n; i++){
        cout << outTime[i] << " ";
    }
    
    cout << "\n";
}

signed main() {
    IOS
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}
