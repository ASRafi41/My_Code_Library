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
void factorize(ll n, vector<ll> &factors) {  // O(N^1/3)
    if (n <= 1) return;
    if (isPrime(n)) { // If prime, add it to factors
        factors.push_back(n);
        return;
    }

    ll factor = pollard_rho(n);
    factorize(factor, factors);
    factorize(n / factor, factors);
}

lll phi(ll x) { // Euler Totient Function => O(N^1/3)
    vector<ll> factors;
    factorize(x, factors);
    sort(factors.begin(), factors.end());
    
    lll phiX = x;
    for(int i = 0; i < factors.size(); ) {
        int j = i + 1;
        while(j < factors.size() && factors[i] == factors[j]) ++j;
        phiX = phiX * (factors[i] - 1) / factors[i];
        i = j;
    }
    return phiX;
}

int main() {
    ll num;
    cin >> num;

    /// ==> Prime Factor <==
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

    cout << "Prime Factors: \n";
    for (auto &[prime, cnt]: pf) cout << prime << " " << cnt << endl;
    cout << endl;

    
    /// ==> Divisors <==
    ll divisorsSum = 0;
    vector<ll> divisors;
    auto divisorSum = [&](auto&& self, int i, ll factor) -> void {
        if(i == pf.size()) {
            divisors.push_back(factor);
            divisorsSum += factor;
            return;
        }
        self(self, i + 1, factor); // not take
        ll val = 1;
        for(int j = 1; j <= pf[i].second; j++) {
            val *= pf[i].first;
            self(self, i + 1, factor * val);
        }
        return;
    };
    divisorSum(divisorSum, 0, 1);
    sort(divisors.begin(), divisors.end());

    cout << "Divisor are: " << endl;
    for(auto &d: divisors) cout << d << " ";
    cout << endl << endl;


    /// ==> Euler Totient Function <==
    cout << "Phi(" << num << ") = " << (ll)phi(num) << endl;
    return 0;
}
