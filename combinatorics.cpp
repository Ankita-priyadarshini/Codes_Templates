#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000001;

int factorialNumInv[N+1], naturalNumInv[N + 1], fact[N + 1];

void InverseofNumber(int p){
    naturalNumInv[0] = naturalNumInv[1] = 1;
    for(int i = 2; i <= N; i++) naturalNumInv[i] = (p - (p / i) * naturalNumInv[p % i] % p) % p;
}

void InverseofFactorial(int p){
    factorialNumInv[0] = factorialNumInv[1] = 1;
    for(int i = 2; i <= N; i++) factorialNumInv[i] = (naturalNumInv[i] * factorialNumInv[i - 1]) % p;
}

void factorial(int p){
    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % p;
}

signed main(){
    int p = 1e9 + 7;
    InverseofNumber(p);
    InverseofFactorial(p);

    factorial(p);

    string s; cin >> s;

    map<char, int> m;

    for(auto i : s) m[i]++;
    int ans = fact[s.size()];

    for(auto i : m){
        ans *= factorialNumInv[i.second];
        ans %= p;
    }

    cout << ans << "\n";
    
    return 0;
}