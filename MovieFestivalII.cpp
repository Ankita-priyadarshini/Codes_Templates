#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

static bool compare(pair<int, int>& a, pair<int, int> &b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a.begin(), a.end(), compare);
    
    int cnt = 0;
    multiset<int> ms;
    for(int i = 0; i < k; i++) ms.insert(-1);
    
    for(int i = 0; i < n; i++){
        auto it = ms.upper_bound(a[i].first);
        if(it == begin(ms)) continue;
        ms.erase(--it);
        ms.insert(a[i].second);
        cnt++;
    }
    
    cout << cnt << "\n";
}

signed main(){
    // int t; cin >> t;
    // while(t--)
    solve();
    return 0;
}