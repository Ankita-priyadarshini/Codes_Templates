#include <bits/stdc++.h>
using namespace std;

int maximumPossible(vector<int>& arr, int n, int val) {
    int initialFreq = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == val) initialFreq++;
    }

    vector<int> gain(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] == val) {
            gain[i] = -1;  
        } else {
            int m = arr[i] ^ val;
            gain[i] = 1; 
        }
    }

    int maxGain = 0, currentGain = 0;
    for (int i = 0; i < n; ++i) {
        currentGain = max(gain[i], currentGain + gain[i]);
        maxGain = max(maxGain, currentGain);
    }

    return initialFreq + maxGain;
}

void solve(){
    int n, val;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cin >> val;
}

int main()
{
    solve();
    return 0;
}