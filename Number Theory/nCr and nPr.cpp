#include <bits/stdc++.h>
#define ll long long
using namespace std;

// nCr and nPr using Modulo
const int Max = 2e5 + 5, mod = 998244353;
ll fact[Max], factInv[Max];

template<class T> T Pow(T a, ll b)
{
    T ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void build_fact()
{
    fact[0] = 1;
    for(int i = 1; i < Max; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    factInv[Max - 1] = Pow(fact[Max - 1], mod - 2);
    for(int i = Max - 2; i >= 0; i--)
    {
        factInv[i] = 1LL * factInv[i + 1] * (i + 1) % mod;
    }
    return;
}

int nCr_mod(int n, int r)
{
    if(n < r or n < 0 or r < 0) return 0;
    return 1LL * fact[n] * factInv[r] % mod * factInv[n - r] % mod;
}
int nPr_mod(int n, int r) // nPr = nCr * r! 
{
    if(n < r or n < 0 or r < 0) return 0;
    return (1LL * nCr_mod(n, r) * fact[r]) % mod;
}
// end

// Without Modulo(Normal)
ll nCr(ll n, ll r)  // O(r * log(n))
{
    ll p = 1, k = 1, m;
    if (n - r < r) r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n, k *= r;
            m = __gcd(p, k);
            p /= m, k /= m;
            n--, r--;
        }
    }
    else p = 1;
    return p;
}

ll Fact(ll n)
{
    if (n <= 1) return 1;
    return n * Fact(n - 1);
}
ll nPr(ll n, ll r) // O(r * r * log(n))
{
    // return Fact(n) / Fact(n - r);
    return nCr(n, r) * Fact(r);
}
// end

int main()
{
    ll n, r;
    cin >> n >> r;

    build_fact(); // <===
    
    cout << "nCr = " << nCr(n, r) << endl; // Without Modulo nCr
    cout << "nCr Mod = " << nCr_mod(n, r) << endl << endl; // nCr using Modulo

    cout << "nPr = " << nPr(n, r) << endl; // Without Modulo nPr
    cout << "nPr Mod = " << nPr_mod(n, r) << endl << endl; // nPr using Modulo
    return 0;
}
