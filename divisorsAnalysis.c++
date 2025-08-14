#include<bits/stdc++.h>
using namespace std;

#define int long long

const int sz = 1e6 + 1;
int factors[sz];

void solve(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        factors[x]++;
    }
    
    for(int i = sz - 1; i >= 1; i--){
        int count = 0;
        for(int j = i; j < sz; j+=i) count += factors[j];
        if(count > 1){
            cout << i << "\n";
            return;
        }
    }
}

signed main(){
    solve();
    return 0;
}