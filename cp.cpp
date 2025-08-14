#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size, rank;

public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution{
public:
    int spannngTree(int n, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> a;

        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];

                a.push_back({wt, {i, adjNode}});
            }
        }

        DisjointSet ds(n);
        sort(a.begin(), a.end());

        int minimumSpanningTreeWeigth = 0;

        for(auto it : a){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                minimumSpanningTreeWeigth += wt;
                ds.unionBySize(u, v);
            }
        }

        return minimumSpanningTreeWeigth;
    }
};