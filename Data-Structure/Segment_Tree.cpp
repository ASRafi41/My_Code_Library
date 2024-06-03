#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define _ASRafi_ ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

const int N = 3e5 + 9;
ll a[N];
ll t[4 * N];

void build(int node, int st, int en)    //=> O(N)
{
    if (st == en) {
        t[node] = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2 * node, st, mid); // divide left side
    build(2 * node + 1, mid + 1, en); // divide right side
    // Merging left and right portion
    auto &Cur = t[node];
    auto &Left = t[2 * node];
    auto &Right = t[2 * node + 1];
    Cur = Left + Right;
}
ll query(int node, int st, int en, int l, int r)   //=> O(log n)
{
    if (st > r || en < l) // No overlapping and out of range
    {
        return 0; // <== careful 
    }
    if (l <= st && en <= r) // Complete overlapped (l-r in range)
    {
        return t[node];
    }
    // Partial overlapping
    int mid = (st + en) >> 1;
    auto Left = query(2 * node, st, mid, l, r);
    auto Right = query(2 * node + 1, mid + 1, en, l, r);
    return Left + Right;
}
void update(int node, int st, int en, int idx, ll val) //=> O(log n)
{
    if (st == en) {
        a[st] = val;
        t[node] = val;
        return;
    }
    int mid = (st + en) >> 1;
    if (idx <= mid) update(2 * node, st, mid, idx, val);
    else update(2 * node + 1, mid + 1, en, idx, val);
    // Merging left and right portion
    auto &Cur = t[node];
    auto &Left = t[2 * node];
    auto &Right = t[2 * node + 1];
    Cur = Left + Right;
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        a[i] = x;
    }
    build(1, 1, n); // Creating Segment tree;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int i, val; cin >> i >> val;
            update(1, 1, n, i, a[i] + val);
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return;
}
int main()
{
    _ASRafi_;
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        // cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}
