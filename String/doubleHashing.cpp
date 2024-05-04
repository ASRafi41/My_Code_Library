#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// collusion rate = 1 / MOD; if i use double hashing collusion rate will be 1 / (MOD1 * MOD2);
// const __int128 MOD = 202206214218227; // More efficient module for the __int128 datatype
// const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9; // You can use those mods.

const int N = 1e6 + 7;
const int Base1 = 137, Base2 = 277;
const int mod1 = 127657753, mod2 = 987654319;

pair<ll, ll> po[N];

struct Hashing
{
    void generatePower() // Storing the power of the Base.
    {
        po[0].first = 1, po[0].second = 1;
        for (int i = 1; i < N; i++)
        {
            po[i].first = (po[i - 1].first * Base1) % mod1;
            po[i].second = (po[i - 1].second * Base2) % mod2;
        }
    }
    vector<pair<ll, ll>> prefix, suffix;
    int n;
    void generatePrefixHash(string &s)
    {
        prefix[0].first = s[0], prefix[0].second = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            prefix[i].first = ((prefix[i - 1].first * Base1) + s[i]) % mod1;
            prefix[i].second = ((prefix[i - 1].second * Base2) + s[i]) % mod2;
        }
    }
    void generateSuffixHash(string &s)
    {
        suffix[n - 1].first = s[n - 1], suffix[n - 1].second = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i].first = ((suffix[i + 1].first * Base1) + s[i]) % mod1;
            suffix[i].second = ((suffix[i + 1].second * Base2) + s[i]) % mod2;
        }
    }
    pair<ll, ll> generateHash(string &s) // return hash value of a string
    {
        pair<ll, ll> H = {0, 0};
        for (auto &c : s)
        {
            H.first = ((H.first * Base1) + c) % mod1;
            H.second = ((H.second * Base2) + c) % mod2;
        }
        return H;
    }
    pair<ll, ll> getPrefixRangeHash(int l, int r) // return hash value of a range
    {
        if (l == 0) return prefix[r];
        pair<ll, ll> Hs;
        Hs.first = (prefix[r].first - (prefix[l - 1].first * po[r - l + 1].first % mod1) + mod1) % mod1;
        Hs.second = (prefix[r].second - (prefix[l - 1].second * po[r - l + 1].second % mod2) + mod2) % mod2;
        return Hs;
    }
    pair<ll, ll> getSuffixRangeHash(int l, int r) // return hash value of a range
    {
        if (r == n - 1) return suffix[l];
        pair<ll, ll> Hs;
        Hs.first = (suffix[l].first - (suffix[r + 1].first * po[r - l + 1].first % mod1) + mod1) % mod1;
        Hs.second = (suffix[l].second - (suffix[r + 1].second * po[r - l + 1].second % mod2) + mod2) % mod2;
        return Hs;
    }
    pair<ll, ll> concat(pair<ll, ll> &hash1, pair<ll, ll> &hash2, int len) //len = 2nd string size
    {
        return {((hash1.first * po[len].first) + hash2.first) % mod1, ((hash1.second * po[len].second) + hash2.second) % mod2};
    }
    void build(string &s)
    {
        n = s.size();
        prefix.resize(n), suffix.resize(n);
        generatePrefixHash(s);
        // generateSuffixHash(s);
        if (po[0].first != 1) generatePower();
    }
} Hash;

void solve()
{
    int n, m;
    string s1, s2;
    s1 = "abcabababc", s2 = "abc";
    // cin >> s1 >> s2;
    n = s1.size();
    Hash.build(s1);

    pair<ll, ll> hashOfS2 = Hash.generateHash(s2);
    for (int i = 0; i + s2.size() <= s1.size(); i++)
    {
        if (Hash.getPrefixRangeHash(i, i + s2.size() - 1) == hashOfS2)
        {
            cout << i << "\n";
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
