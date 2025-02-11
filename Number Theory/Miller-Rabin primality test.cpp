#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using lll = __int128_t;

ll Pow(ll a, ll b, ll mod) { // O(log b)
    ll ans = 1 % mod;
    a %= mod;
    if(a < 0) a += mod;
    while (b) {
        if(b & 1) ans = (lll)ans * a % mod;
        a = (lll)a * a % mod;
        b >>= 1;
    }
    return ans;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = Pow(a, d, n);
    if(x == 1 or x == n - 1) return false;
    for(int r = 1; r < s; r++) {
        x = (lll)x * x % n;
        if(x == n - 1) return false;
    }
    return true;
}

bool isPrime(ll n) { // MillerRabin => O(k * log(n))
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;

    int r = 0;
    ll d = n - 1;
    while((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { // k = this array size
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll p;
    cin >> p;
    if(isPrime(p)) cout << p << " is Prime Number." << endl;
    else cout << p << " is not Prime Number." << endl;
    return 0;
}