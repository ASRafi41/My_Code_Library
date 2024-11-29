// Problem link: https://cses.fi/problemset/task/1654/

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int MLOG = 20; // Maximum number of bits (size of set U)
const ll MAXN = (1LL << MLOG); 

void sum_over_supersets(vector<ll> &dp) { // adding element to all its super set (x | y = x)
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int i = 0; i < MAXN; ++i) {
            if (i & (1 << bit)) {
                dp[i] += dp[i ^ (1 << bit)];
                // mx[i] = max(mx[i], mx[i ^ (1 << bit)]);
            }
        }
    }
}

void sum_over_subsets(vector<ll> &dp) { // add elements to its subsets (x & y = x)
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int i = MAXN - 1; i >= 0; --i) {
            if (i & (1 << bit)) {
                dp[i ^ (1 << bit)] += dp[i];
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> val(n), dp1(MAXN, 0), dp2(MAXN, 0);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        val[i] = x;
        dp1[x] += 1; // frequency count
        dp2[x] += 1; // frequency count
    }

    // build
    sum_over_supersets(dp1);
    sum_over_subsets(dp2);

    for(int i = 0; i < n; i++) {
        ll ans1 = dp1[val[i]]; // x | y = x
        ll ans2 = dp2[val[i]]; // x & y = x
        ll ans3 = n - dp1[(MAXN - 1) ^ val[i]]; // x & y != 0 => n - [CNT of x & y == 0];
        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }
    return;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
