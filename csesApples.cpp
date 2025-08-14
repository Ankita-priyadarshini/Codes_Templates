#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAX = 2000000;

int fact[MAX + 1], invFact[MAX + 1];

int powMod(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    invFact[MAX] = powMod(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}


int nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

signed main() {
    int n, m;
    cin >> n >> m;
    
    precomputeFactorials();
    
    int result = nCr(n + m - 1, n - 1);
    cout << result << "\n";
    
    return 0;
}
