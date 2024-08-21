#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

const int N = 3e5 + 9;

struct Segment_Tree {
    ll t[4 * N];

    auto merge(auto &l, auto &r) { // <= Change this function
        return l + r;
    }
    void build(int node, int st, int en, vector<ll> &arr) { //=> O(N)
        if (st == en) {
            t[node] = arr[st];
            return;
        }
        int mid = (st + en) >> 1;
        build(node << 1, st, mid, arr); // divide left side
        build(node << 1 | 1, mid + 1, en, arr); // divide right side
        // Merging left and right portion
        auto &Cur = t[node];
        auto &Left = t[node << 1];
        auto &Right = t[node << 1 | 1];
        Cur = merge(Left, Right);
        return;
    }
    void update(int node, int st, int en, int idx, ll val) { //=> O(log n)
        if (st == en) {
            t[node] = val;
            return;
        }
        int mid = (st + en) >> 1;
        if (idx <= mid) update(node << 1, st, mid, idx, val);
        else update(node << 1 | 1, mid + 1, en, idx, val);
        // Merging left and right portion
        auto &Cur = t[node];
        auto &Left = t[node << 1];
        auto &Right = t[node << 1 | 1];
        Cur = merge(Left, Right);
        return;
    }
    ll query(int node, int st, int en, int l, int r) { //=> O(log n)
        if (st > r || en < l) { // No overlapping and out of range
            return 0; // <== careful 
        }
        if (l <= st && en <= r) { // Complete overlapped (l-r in range)
            return t[node];
        }
        // Partial overlapping
        int mid = (st + en) >> 1;
        auto Left = query(node << 1, st, mid, l, r);
        auto Right = query(node << 1 | 1, mid + 1, en, l, r);
        return merge(Left, Right);
    }
} st;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        v[i] = x;
    }
    st.build(1, 1, n, v); // Creating Segment tree;
    while (q--) {
        short type; cin >> type;
        if (type == 1) {
            int i, val; cin >> i >> val;
            st.update(1, 1, n, i, v[i] + val);
            v[i] += val;
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.query(1, 1, n, l, r) << endl;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0), cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        // cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}
