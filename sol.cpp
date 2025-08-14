#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define IOS                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define fr(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> a;
    
    fr(i, n){
        int x; cin >> x;
        a.push_back({x, i});
    }
    
    sort(all(a));
    
    for(int i = 0; i < n; i++){
        int left = x - a[i].first;
        
        int l = 0, r = n - 1;
        while(l != r){
            if(l != i && r != i && a[l].first + a[r].first == left){
                cout << a[i].second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1 << endl;
                return;
            }
            
            if(a[l].first + a[r].first <= left) l++;
            else r--;
        }
    }
    
    cout << "IMPOSSIBLE\n";
}

signed main() {
    IOS
    solve();
    return 0;
}