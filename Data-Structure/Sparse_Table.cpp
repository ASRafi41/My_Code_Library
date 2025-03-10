#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 0-based indexing, query finds in range [first, last]
#define lg(x) (31 - __builtin_clz(x))
const int N = 3e5 + 7;
const int K = lg(N);

struct sparse_table {
    ll tr[N][K + 1];

    ll f(ll p1, ll p2) { // Change this function according to the problem.
        return p1 + p2; // <===
    }

    void build(int n, const vector<ll> &a) { // O(N * logN)
        for (int i = 0; i < n; i++) {
            tr[i][0] = a[i];
        }
        for (int j = 1; j <= K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                tr[i][j] = f(tr[i][j - 1], tr[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll query1(int l, int r) { // find Non-Idempotent Operations (Sum, LCM, XOR) => O(LogN)
        ll val = 0; // for sum or, xor => val = 0 and lcm => val = 1
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                val = f(val, tr[l][j]);
                l += 1 << j;
            }
        }
        return val;
    }

    ll query2(int l, int r) { // find Idempotent Operations (Min, Max, GCD, AND, OR) => O(1)
        int d = lg(r - l + 1);
        return f(tr[l][d], tr[r - (1 << d) + 1][d]);
    }
} spt;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[i] = x;
    }
    spt.build(n, v); // <== Sparse Table Build
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << spt.query1(l, r) << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
