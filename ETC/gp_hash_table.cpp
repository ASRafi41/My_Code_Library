#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct pair_hash // Compare the functions for gp_hash_table and unordered_map.
{ 
    template <typename T, typename U>
    size_t operator()(const pair<T, U> &p) const
    {
        auto hash1 = hash<T>{}(p.first);
        auto hash2 = hash<U>{}(p.second);
        return hash1 ^ hash2;
    }
};

int32_t main()
{
    int n, k;
    cin >> n;
    // gp_hash_table<pair<ll, int>, int, pair_hash> gph;
    gp_hash_table<char, int> gph; // SAME AS unordered_map; But, More Faster;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch >> k;
        gph[ch] = k;
    }
    for (auto i : gph)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << gph.find('c')->second << endl;
    return 0;
}