#include<bits/stdc++.h>
typedef long long  ll;
#define endl       '\n'
#define _ASRafi_   ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

const int N = 1e5 + 10;
int a[N];
int tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);                         // divide left side
    build(2 * node + 1, mid + 1, en);                 // divide right side
    tree[node] = tree[2 * node] + tree[2 * node + 1]; // sum of left and right side
}
int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l) // No overlapping and out of range
    {
        return 0;
    }
    if (l <= st && en <= r) // Complete overlapped (l-r in range)
    {
        return tree[node];
    }
    // Partial overlapping
    int mid = (st + en) / 2;

    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}
void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * node, right = 2 * node + 1;
    if (idx <= mid) update(left, st, mid, idx, val);
    else update(right, mid + 1, en, idx, val);
    tree[node] = tree[left] + tree[right];
}
void solve()
{
    ll n, q, k1, c = 0, ans = 0;
    cin >> n >> q;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
    }
    build(1, 0, n - 1); // Createing Segment tree;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >> i;
            cout << a[i] << endl;
            update(1, 0, n - 1, i, 0);
        }
        else if (type == 2)
        {
            int i, val;
            cin >> i >> val;
            update(1, 0, n - 1, i, a[i] + val);
            // cout<<tree[1]<<endl;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
    return;
}
int main()
{
    _ASRafi_
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; ++i)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
