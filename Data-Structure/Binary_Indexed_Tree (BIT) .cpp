// https://cses.fi/problemset/task/1137/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

template <class T>
struct BIT { // 1-indexed
    int n;
    vector<T> t;
    BIT() {}
    BIT(int _n) {
        n = _n;
        t.assign(n + 1, 0);
    }
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i)) t[i] += val;
    }
    void update(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector<vector<int>> g(n + 1);
    int u, v;
    for(int i = 1; i + 1 <= n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> st(n + 1), en(n + 1);
    int time = 0;

    auto dfs = [&](auto&& self, int u, int par) -> void {
        st[u] = ++time;
        for(auto &v: g[u]) {
            if(v == par) continue;
            self(self, v, u);
        }
        en[u] = time;
    };

    dfs(dfs, 1, -1);
    BIT<ll> bit1(n + 1); // <===
    for(int i = 1; i <= n; i++) {
        bit1.update(st[i], val[i]);
    }

    short type; 
    int s, x;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> s >> x;
            bit1.update(st[s], -val[s]);
            val[s] = x;
            bit1.update(st[s], +val[s]);
        }
        else {
            cin >> s;
            cout << bit1.query(st[s], en[s]) << endl;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
