#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()

typedef long long ll;

class unionFind{
    private: vector<ll> par, rank;
    public:
        unionFind(ll n){
            rank.assign(n, 0);
            par.resize(n);
            iota(all(par), 0);
        }

        ll findSet(ll i){
            return (par[i] == i) ? i : par[i] = findSet(par[i]);
        }

        bool isSameSet(ll i, ll j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                ll x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) par[y] = x;
                else{
                    par[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

void solve(){

}

int main(){
    int t; cin >> t; while(t--)
    solve();
    return 0;
}