// Problem link: https://judge.eluminatis-of-lu.com/p/1082

#include<bits/stdc++.h>
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define error1(x)   cerr<<#x<<" = "<<(x)<<endl
#define error2(a,b) cerr<<"("<<#a<<", "<<#b<<") = ("<<(a)<<", "<<(b)<<")\n";
#define coutall(v)  for(auto &it: v) cout << it << " "; cout << endl;
using namespace std;
using ll = long long;

const int N = 3e5 + 3;

struct Merge_Sort_Tree {
    vector<vector<ll>> t;

    Merge_Sort_Tree() {
        t.resize(4 * N, {});
    }

    void build(int node, int st, int en, vector<ll> &arr) { //=> O(N log N)
        t[node].clear();
        if (st == en) {
            t[node] = {arr[st]};
            return;
        }
        int mid = (st + en) >> 1;
        build(node << 1, st, mid, arr); // divide left side
        build(node << 1 | 1, mid + 1, en, arr); // divide right side

        // Merging left and right portion
        auto &Cur = t[node];
        auto &Left = t[node << 1];
        auto &Right = t[node << 1 | 1];
        
        merge(make_move_iterator(Left.begin()), make_move_iterator(Left.end()),
              make_move_iterator(Right.begin()), make_move_iterator(Right.end()),
              back_inserter(Cur));
    }
    // *** For update function, using set => O(log N * log N)
    void update(int node, int st, int en, int idx, ll val) { //=> O(N log N)
        if (st == en) {
            t[node] = {val};
            return;
        }
        int mid = (st + en) >> 1;
        if (idx <= mid) update(node << 1, st, mid, idx, val);
        else update(node << 1 | 1, mid + 1, en, idx, val);

        // Merging left and right portion
        auto &Cur = t[node];
        auto &Left = t[node << 1];
        auto &Right = t[node << 1 | 1];

        Cur.clear();
        merge(make_move_iterator(Left.begin()), make_move_iterator(Left.end()),
              make_move_iterator(Right.begin()), make_move_iterator(Right.end()),
              back_inserter(Cur));
    }
    ll query(int node, int st, int en, int l, int r, ll val) { //=> O(log N * log N)
        // assert(l <= r); // <==
        if (st > r || en < l) { // No overlapping and out of range
            return 0; // <== careful 
        }
        if (l <= st && en <= r) { // Complete overlapped (l-r in range)
            return lower_bound(all(t[node]), val) - t[node].begin();
        }
        // Partial overlapping
        int mid = (st + en) >> 1;
        auto Left = query(node << 1, st, mid, l, r, val);
        auto Right = query(node << 1 | 1, mid + 1, en, l, r, val);
        return Left + Right;
    }
} st1;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    st1.build(1, 1, n, v); // <==

    int q, l, x, r;
    cin >> q;
    while(q--) {
        cin >> l >> x >> r;

        ll leftMn = st1.query(1, 1, n, l, x - 1, v[x]);
        ll leftMx = (x - l) - st1.query(1, 1, n, l, x - 1, v[x] + 1);

        ll rightMn = st1.query(1, 1, n, x + 1, r, v[x]);
        ll rightMx = (r - x) - st1.query(1, 1, n, x + 1, r, v[x] + 1);

        cout << (leftMn * rightMx) + (leftMx * rightMn) << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
