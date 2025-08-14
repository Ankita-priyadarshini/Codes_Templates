#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()

const int mod = 1e9 + 7;

void dfs(int i, vector<vector<int>>& edges, int parent, vector<int>& maxDistLeafInSubtree){
    // leaf cases
    maxDistLeafInSubtree[i] = 0;
    
    for(auto it : edges[i]){
        if(it != parent){
            dfs(it, edges, i, maxDistLeafInSubtree);
            maxDistLeafInSubtree[i] = max(maxDistLeafInSubtree[i], 1 + maxDistLeafInSubtree[it]);
        }
    }
}

void dfs1(int i, vector<vector<int>>& edges, int parent, vector<int>& maxDistLeafInSubtree, vector<int>& maxDistLCA){
    vector<int> maxLeavesInChildren;
    
    for(auto it : edges[i]){
        if(it != parent){
            maxLeavesInChildren.push_back(maxDistLeafInSubtree[it]);
            dfs1(it, edges, i, maxDistLeafInSubtree, maxDistLCA);
        }
    }
    
    if(maxLeavesInChildren.size() == 0){
        maxDistLCA[i] = 0;
    }else if(maxLeavesInChildren.size() == 1){
        maxDistLCA[i] = maxLeavesInChildren[0] + 1;
    }else{
        sort(maxLeavesInChildren.begin(), maxLeavesInChildren.end());
        reverse(maxLeavesInChildren.begin(), maxLeavesInChildren.end());
        
        maxDistLCA[i] = maxLeavesInChildren[0] + maxLeavesInChildren[1] + 2;
    }
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
    
    vector<int> maxDistLeafInSubtree(n + 1, -1);
    vector<int> maxDistLCA(n + 1, -1);
    dfs(1, edges, -1, maxDistLeafInSubtree);
    dfs1(1, edges, -1, maxDistLeafInSubtree, maxDistLCA);
    
    for(int i = 1; i <= n; i++){
        cout << maxDistLCA[i] << " ";
    }
}

signed main() {
    IOS
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}
