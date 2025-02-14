#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using lll = __int128_t;

const int N = 1e8 + 7;
int marked[N / 64 + 2];

#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))

bool isPrime1(int num) {
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

void sieve() {
    for (int i = 3; i * i < N; i += 2) {
        if (!on(i)) {
            for (int j = i * i; j <= N; j += i + i) {
                mark(j);
            }
        }
    }
}

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

// Pollard’s Rho Algorithm to Find a Factor
ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ll> distX(2, n - 1);
    uniform_int_distribution<ll> distC(1, n - 1);
    
    ll x = distX(rng), y = x;
    ll c = distC(rng);
    ll g = 1;

    auto mult = [&](ll a, ll b, ll mod) -> ll { return (lll) a * b % mod; };
    auto f = [&](ll x) { return (mult(x, x, n) + c) % n; };
    
    while (g == 1) {
        x = f(x);
        y = f(f(y));
        g = __gcd(abs(x - y), n);
    }
    return g;
}

// Function to Find All Prime Factors
void factorize(ll n, vector<ll> &factors) {
    if (n <= 1) return;
    if ((n < N ? isPrime1(n) : isPrime(n))) { // If prime, add it to factors
        factors.push_back(n);
        return;
    }

    ll factor = pollard_rho(n);
    factorize(factor, factors);
    factorize(n / factor, factors);
}

int main() {
    sieve(); // <==== prime build
    ll num;
    cin >> num;

    vector<ll> factors;
    factorize(num, factors);
    sort(factors.begin(), factors.end());
    
    vector<pair<ll, int>> pf;
    for(int i = 0; i < factors.size(); ) {
        int j = i + 1;
        while(j < factors.size() && factors[i] == factors[j]) ++j;
        pf.push_back({factors[i], j - i});
        i = j;
    }

    cout << "Factors: \n";
    for (auto &[prime, cnt]: pf) cout << prime << " " << cnt << endl;
    return 0;
}
