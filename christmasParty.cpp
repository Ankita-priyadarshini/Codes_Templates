#include<bits/stdc++.h>
using namespace std;

#define int long long

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}

int modInverse(int a, int mod) {
    return power(a, mod - 2, mod);
}

signed main(){
    int mod = 1e9 + 7;

    int n;
    cin >> n;

    if(n == 1){
        cout << "0\n" ;
        return 0;
    }

    vector<int> fact(n + 1, 0);

    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;

    for(int i = 3; i <= n; i++){
        fact[i] = ((fact[i - 1]) % mod * (i %  mod)) % mod;
    }

    int ans = 0;
    int sign = 1;

    for(int i = 2; i <= n; i++){
        int modInvVal = modInverse(fact[i], mod);
        int s = ((fact[n] % mod) * (modInvVal % mod)) % mod;

        if(sign == 1) ans = ((ans % mod) + (s % mod)) % mod;
        else ans = ((ans % mod) - (s % mod) + mod) % mod;

        sign *= -1;
    }

    cout << ans << "\n";
    return 0;
}