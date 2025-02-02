// Time Complexity -> O(log(b)); 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll Pow(ll a, ll b, ll mod = 1e9 + 7) { // O(log b)
    ll ans = 1 % mod;
    a %= mod;
    if(a < 0) a += mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a = 2, b = 92;
    cout << a << "^" << b << " = " << Pow(a, b) << endl;

    // long double x = 2.6769;
    // cout << x << "^" << b << " = " << Pow(x, b) << endl;

    return 0;
}
