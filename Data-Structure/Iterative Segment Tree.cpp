// problem link: https://cses.fi/problemset/task/1648
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 2e5 + 3;

struct Segment_Tree { // 1'base
    ll t[2 * N];

    auto merge(auto &l, auto &r) { // <==
        return l + r;
    }
    void build(int node, int st, int en, auto &arr) {
        int n = en - st + 1;
        for(int i = 1; i <= n; i++) t[n + i - 1] = arr[i]; 
        for (int i = n - 1; i > 0; --i)
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }
    void update(int node, int st, int en, int idx, ll val) {
        int n = en - st + 1;
        int p = (idx - st) + n;
        t[p] = val;
        for (p >>= 1; p > 0; p >>= 1)
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }
    ll query(int node, int st, int en, int l, int r) {
        int n = en - st + 1;
        int L = (l - st) + n, R = (r - st) + n;
        ll ans = 0; // <==
        for (; L <= R; L >>= 1, R >>= 1) {
            if (L & 1) ans = merge(ans, t[L++]);
            if (!(R & 1)) ans = merge(ans, t[R--]);
        }
        return ans;
    }
} st1;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st1.build(1, 1, n, a); // <==
    while (q--) {
        int type; cin >> type;
        if(type == 1) {
            int k, u;
            cin >> k >> u;
            st1.update(1, 1, n, k, u);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st1.query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
