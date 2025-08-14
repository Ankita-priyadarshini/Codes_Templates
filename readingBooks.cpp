#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int maxi = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0LL);
    
    if(sum < maxi * 2){
        cout << maxi * 2 << "\n";
    }else{
        cout << sum << "\n";
    }
}

signed main(){
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}