#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

const int mod = 1e9 + 7;

int binaryExpo(int a, int b, int mod){
    int result = 1;
    while(b){
        if(b & 1) result *= a; result %= mod;
        a *= a; a %= mod;
        b >>= 1;
    }
    return result % mod;
}

int modInverse(int x, int mod){
    return binaryExpo(x, mod - 2, mod);
}

int nCr(int n, int r, int mod){
    if(n < r) return 0;
    if(r == 0) return 1;
    
    int fact[n + 1];
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; i++) fact[i] = ((fact[i - 1]) % mod * (i % mod)) % mod;
    
    return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}

signed main(){
    int t;
    cin >> t;

    while(t--){
        int x, y, z;
        cin >> x >> y >> z;

        y = binaryExpo(y, z, 1e9 + 6);
        int result = binaryExpo(x, y, 1e9 + 7);

        cout << result << "\n";
    }
    return 0;
}