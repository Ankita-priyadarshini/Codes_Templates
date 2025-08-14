#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    double median = 0;
    
    if(n & 1){
        median = a[n / 2];
    }else{
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    }
    
    int ans = 0;
    
    for(auto it : a) ans += abs(it - median);
    
    cout << ans << "\n";
}

signed main(){
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}