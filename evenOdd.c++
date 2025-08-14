#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m, k;
    cin >> m >> k;

    vector<string> st(k);

    for(int i = 0; i < k; i++){
        cin >> st[i];
    }

    int evenSum = 0, oddSum = 0;
    
    for(int i = 0; i < k; i++){
        int odd = 0;
        int even = 0;
        for(int j = 0; j < st[i].size(); j++){
            int val = st[i][j];
            if(val % 2 == 0)even++;
            else odd++;
        }
        if(even) evenSum++;
        else oddSum++;
    }

    if(oddSum % 2){
        cout << "ODD\n";
    }else{
        cout << "EVEN\n";
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}