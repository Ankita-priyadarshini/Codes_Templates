#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Hash{
    const int mod = 1e9 + 7, base1 = 5689, base2 = 8861;
    
    vector<pair<int, int>> hashes, Pow;
    
    Hash(string s){
        hashes.assign(s.size() + 1, {0, 0});
        Pow.assign(s.size() + 1, {1, 1});
        
        for(int i = 0; i < s.size(); i++){
            hashes[i + 1] = {(1ll * hashes[i].first * base1 + (s[i] - 'a' + 1)) % mod, (1ll * hashes[i].second * base2 + (s[i] - 'a' + 1)) % mod};
            Pow[i + 1] = {(1ll * Pow[i].first * base1) % mod, (1ll * Pow[i].second * base2) % mod};
        }
    }
    
    pair<int, int> get(int l, int r){
        l++; r++;
        
        int hash1 = (hashes[r].first - (1ll * hashes[l - 1].first * Pow[r - l + 1].first % mod) + mod) % mod;
        int hash2 = (hashes[r].second - (1ll * hashes[l - 1].second * Pow[r - l + 1].second % mod) + mod) % mod;
        
        return {hash1, hash2};
    }
};

void solve(){
    
}

signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
