#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1e8 + 7;
int marked[N / 64 + 2];
#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))

void sieve() {
    for (int i = 3; i * i < N; i += 2) {
        if (!on(i)) {
            for (int j = i * i; j <= N; j += i + i) {
                mark(j);
            }
        }
    }
}

bool isPrime(int num) {
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

ll isqrt(ll x) {
    ll r = sqrtl(x);
    while (r * r > x) r--;
    while ((r + 1) * (r + 1) <= x) r++;
    return r;
}

// count divisors in O(n^{1/3})
ll count_divisors(ll n) {
    ll cnt = 1;
    ll limit = cbrt((long double)n) + 2;
    for (ll p = 2; p <= limit && p * p <= n; ++p) {
        if (n % p) continue;
        ll e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        cnt *= (e + 1);
    }
    if(n == 1) return cnt;
    if(isPrime(n)) cnt *= 2;
    else {
        ll r = isqrt(n);
        if(r * r == n && isPrime(r)) cnt *= 3;
        else cnt *= 4;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    sieve(); // <==
    ll n = 18; // 18 => 1, 2, 3, 6, 9, 18
    cin >> n;
    cout << count_divisors(n) << endl;
    return 0;
}
