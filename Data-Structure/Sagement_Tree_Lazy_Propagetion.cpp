#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 5e5 + 9;

struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    ll t[4 * N], lazy[4 * N];
    ST() {
        for (int i = 0; i < 4 * N; i++)
            t[i] = lazy[i] = 0;
    }
    
    inline void push(int n, int st, int en) {
        if (lazy[n] == 0) return;
        t[n] = t[n] + lazy[n] * (en - st + 1);
        if (st != en) {
            lazy[lc] = lazy[lc] + lazy[n];
            lazy[rc] = lazy[rc] + lazy[n];
        }
        lazy[n] = 0;
    }

    inline void pull(int n) {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int st, int en, vector<ll> &arr) {
        lazy[n] = 0; // set lazy default value = 0
        if (st == en) {
            t[n] = arr[st];
            return;
        }
        int mid = (st + en) >> 1;
        build(lc, st, mid, arr);
        build(rc, mid + 1, en, arr);
        pull(n);
    }
    void update(int n, int st, int en, int l, int r, ll v) {
        push(n, st, en);  // push the value left and right child
        if (r < st || en < l) return;
        if (l <= st && en <= r) {
            lazy[n] = v; // set lazy
            push(n, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(lc, st, mid, l, r, v);
        update(rc, mid + 1, en, l, r, v);
        pull(n);
    }

    inline ll combine(ll a, ll b) {
        return a + b;
    }
    ll query(int n, int st, int en, int l, int r) {
        push(n, st, en);
        if (l > en || st > r) return 0; // return null
        if (l <= st && en <= r) return t[n];
        int mid = (st + en) >> 1;
        return combine(query(lc, st, mid, l, r), query(rc, mid + 1, en, l, r));
    }
} st;

int32_t main() {
    int n, q, l, r, v;
    cin >> n >> q;
    vector<ll> vec(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec[i];
    st.build(1, 1, n, vec); // Building the Segment tree
    while (q--) {
        short type;
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> v;
            st.update(1, 1, n, l, r, v);
        }
        else {
            cin >> l >> r;
            cout << st.query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
