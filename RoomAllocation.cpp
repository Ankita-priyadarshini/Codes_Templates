#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

struct person{
    int arrival, departure, index;
};

void solve(){
    int n;
    cin >> n;
    
    int cnt = 0;
    vector<person> arr(n);
    vector<int> answer(n);
    set<pair<int, int>> rooms;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].arrival >> arr[i].departure;
        arr[i].index = i;
    }
    
    sort(arr.begin(), arr.end(), [&](auto a, auto b){
        return a.arrival < b.arrival;
    });
    
    for(auto person : arr){
        int roomNo;
        
        if(rooms.empty() || (*rooms.begin()).first > person.arrival){
            roomNo = ++cnt;
        }else{
            roomNo = (*rooms.begin()).second;
            rooms.erase(rooms.begin());
        }
        
        answer[person.index] = roomNo;
        rooms.insert({person.departure + 1, roomNo});
    }
    
    cout << cnt << "\n";
    for(auto &it : answer) cout << it << " ";
    cout << "\n";
}

signed main(){
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}