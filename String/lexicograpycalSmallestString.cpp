#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define _ASRafi__ ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using ll = long long;
using namespace std;
using namespace __gnu_pbds;

const int N = 1e6 + 5;
const int Base1 = 137, Base2 = 277;
const int mod1 = 127657753, mod2 = 987654319;

bool CalPow = 0;
pair<ll, ll> po[N];
void generatePower() // Storing the power of the Base.
{
    po[0].first = 1, po[0].second = 1;
    for (int i = 1; i < N; i++)
    {
        po[i].first = (po[i - 1].first * Base1) % mod1;
        po[i].second = (po[i - 1].second * Base2) % mod2;
    }
}
struct Hashing
{
    pair<ll, ll> prefix[N], suffix[N];
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
    pair<ll, ll> concat(pair<ll, ll> &hash1, pair<ll, ll> &hash2, int len)
    {
        return {((hash1.first * po[len].first) + hash2.first) % mod1, ((hash1.second * po[len].second) + hash2.second) % mod2};
    }
    void build(string &s)
    {
        n = s.size();
        generatePrefixHash(s);
        // generateSuffixHash(s);
        if (!CalPow) generatePower(), CalPow = 1;
    }
} Hash;

string s;
int lcp(int i, int j, int x, int y) // return the longest common prefix of two string in O(log(n))
{ 
    int l = 1, r = min(j - i + 1, y - x + 1);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Hash.getPrefixRangeHash(i, i + mid - 1) == Hash.getPrefixRangeHash(x, x + mid - 1))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
// 0 means equal
//-1 means first one is smaller
// 1 means first one is larger
int compare(int i, int j, int x, int y)
{
    int lc = lcp(i, j, x, y);
    int len1 = j - i + 1, len2 = y - x + 1;
    if (len1 == len2 && lc == len1) return 0;
    else if (lc == len1) return -1;
    else if (lc == len2) return 1;
    else return (s[i + lc] < s[x + lc] ? -1 : 1);
}
void solve()
{
    cin >> s;
    int len = s.size();
    s += s;     // circular string
    int n = s.length();
    Hash.build(s);

    int mni = 0, mnj = len - 1;
    for (int i = 1; i + len - 1 < n; i++)
    {
        int x = compare(mni, mnj, i, i + len - 1);
        if (x == 1)
        {
            mni = i;
            mnj = i + len - 1;
        }
    }
    cout << s.substr(mni, len) << endl;
    return;
}

int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}
