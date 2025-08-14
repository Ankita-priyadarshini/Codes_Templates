#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;

int getRandomNumber(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

//--------------------------------------------------------CODE HERE --------------------------------------------------------

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> adj(n + 1);

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<int> subtree(n + 1, 1), ans(n + 1);
	
	function<int(int, int, int)> dfs = [&](int node, int par, int depth) {
		int answer = depth;
		for(auto it : adj[node]){
		    if(it != par){
		        answer += dfs(it, node, depth + 1);
		        subtree[node] += subtree[it];
		    }
		}
		return answer;
	};
	
	function<void(int, int, int)> reroot = [&](int node, int par, int answer){
	    ans[node] = answer;
	    for(auto& it : adj[node]) if(it != par) reroot(it, node, answer + n - 2 * subtree[it]);
	};

	reroot(1, 0, dfs(1, 0, 0));
	
	for(int i = 1; i <= n; i++){
	    cout << ans[i] << " ";
	}
}

signed main() {
	IOS
// 	int t; cin >> t; while (t--)
	solve();
	return 0;
}
