#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int parent, map<int, vector<int>> &adj, vector<int> &vis)
{
    int cnt = 1;
    vis[i] = 1;

    for (auto it : adj[i])
    {
        if (it == parent)
            continue;
        cnt += dfs(it, i, adj, vis);
    }

    return cnt;
}

void solve(map<int, vector<int>> &adj, vector<pair<int, int>> &edges)
{
    int e = edges.size();
    int n = adj.size();
    for (int i = 0; i < e; i++)
    {
        int element1 = edges[i].first;
        int element2 = edges[i].second;

        adj[element1].erase(remove(adj[element1].begin(), adj[element1].end(), element2), adj[element1].end());

        adj[element2].erase(remove(adj[element2].begin(), adj[element2].end(), element1), adj[element2].end());
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cout << dfs(i, -1, adj, vis) << " ";
            }
            cout << "\n";
        }
    }
}
