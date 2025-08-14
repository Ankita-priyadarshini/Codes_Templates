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
    
    void update(int idx, char ch, const string &s) {
        // Recompute hash values starting from idx
        for (int i = idx; i < s.size(); i++) {
            hashes[i + 1] = {(hashes[i].first * base1 + (s[i] - 'a' + 1)) % mod,
                             (hashes[i].second * base2 + (s[i] - 'a' + 1)) % mod};
        }
    }
    
    pair<int, int> get(int l, int r){
        l++; r++;
        
        int hash1 = (hashes[r].first - (1ll * hashes[l - 1].first * Pow[r - l + 1].first % mod) + mod) % mod;
        int hash2 = (hashes[r].second - (1ll * hashes[l - 1].second * Pow[r - l + 1].second % mod) + mod) % mod;
        
        return {hash1, hash2};
    }
    
    string set(int idx, char ch){
        
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    Hash a(s);
    
    string t = s;
    reverse(t.begin(), t.end());
    Hash b(t);
    
    for(int i = 0; i < m; i++){
        int type; cin >> type;
        
        if(type == 1){
            int index; char ch;
            cin >> index >> ch;
            index--;
            s[index] = ch;
            a.update(index, ch, s);
            
            t[n - index - 1] = ch;
            b.update(n - index - 1, ch, t);
        }else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            pair<int, int> hashAtoB = a.get(l, r);
            pair<int, int> hashRevAtoB = b.get(n - r - 1, n - l - 1);

            if (hashAtoB == hashRevAtoB)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
}

signed main(){
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
