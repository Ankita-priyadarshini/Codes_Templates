#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> podsCost(n);
    vector<int> pods(n);
    vector<int> cost(n);

    for(int i = 0; i < n; i++){
        cin >> pods[i];
    }

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    for (int i = 0; i < n; i++) {
        podsCost[i] = {cost[i], pods[i]};  
    }

    sort(podsCost.begin(), podsCost.end());

    int total = 0;
    set<int> st;

    for (int i = 0; i < n; ++i) {
        int currcost = podsCost[i].first;  
        int currpod = podsCost[i].second;

        auto isPresent = st.find(currpod);

        if (isPresent != st.end()) {
            // total += podsCost[isPresent].second;  
            st.erase(isPresent);  
        }

        st.insert({currcost, currpod});
    }

    cout << total << "\n";

    cout << total << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}