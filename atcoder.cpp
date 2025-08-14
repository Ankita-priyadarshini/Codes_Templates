#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define fr(i, n) for (int i = 0; i < n; i++)

void solve() {
    string s; int n, k; cin >> n >> k >> s;
    
    string r = s;
    for(int i = 1; i < (int)s.size(); i++){
        if(s[i - 1] == 'o') r[i] = '.';
    }
    
    for(int i = (int)s.size() - 1; i >= 1; i--){
        if(s[i] == 'o') r[i - 1] = '.';
    }
     
    int os = count(all(r), 'o');
    int qs = count(all(r), '?');
    
    if(k - os && qs > k - os){
        if(qs - (k - os) != 1) cout << r << "\n";
        else{
            for(int i = 1; i < (int)r.size(); i++){
                if(r[i - 1] == '.' && r[i] == '?') r[i] = 'o';
            }
            
            for(int i = (int)r.size() - 1; i >= 0; i--){
                if(r[i] == '.' && r[i - 1] == '?') r[i - 1] = 'o';
            }
            
            for(int i = (int)r.size() - 1; i >= 0; i--){
                if(r[i] == '?') r[i] = '.';
            }
            
            cout << r << "\n";
        }
    }else if(qs == k - os){
        for(int i = 0; i < (int)r.size(); i++){
            if(r[i] == '?') r[i] = 'o';
        }
        cout << r << "\n";
    }else if(k - os == 0 && qs){
        for(int i = 0; i < (int)r.size(); i++){
            if(r[i] == '?') r[i] = '.';
        }
        cout << r << "\n";
    }
}

signed main() {
	IOS
    // int t; cin >> t; while(t--)
	solve();
	return 0;
}