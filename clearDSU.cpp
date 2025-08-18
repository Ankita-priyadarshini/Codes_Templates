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
    private: vector<ll> par, rank, sz; 
    public:
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
    
    unionFind u(n);
    ll maxi = 1;
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        u.unionSet(x, y);
        maxi = max(maxi, u.sizeOf(x));
        cout << cnt << " " << maxi << "\n";
    }
}

int main() {
	IOS
// 	ll t; cin >> t; while(t--)
	solve();
	return 0;
}