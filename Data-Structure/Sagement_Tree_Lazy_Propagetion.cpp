#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5 + 10;
ll a[N], tree[4 * N], lazy[4 * N];

void Propagate(int node, int st, int en)
{
    if (lazy[node] == -1 || st==en) return;
    //carefully handle this conditions
    tree[node * 2] = lazy[node];
    lazy[node * 2] = lazy[node];

    tree[node * 2 + 1] = lazy[node];
    lazy[node * 2 + 1] = lazy[node];

    tree[node]=0;
    lazy[node] = -1;
}
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
ll query(int node, int start, int end, int l, int r, ll propVal = 0)
{
    if (start > r || end < l) return 0;
    if (start >= l && end <= r)
    {
        return tree[node] + ((end - start + 1) * propVal);
    }
    int mid = (start + end) / 2;
    ll p1 = query(2 * node, start, mid, l, r, propVal + lazy[node]);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r, propVal + lazy[node]);
    return p1 + p2;
}
void update(int node, int start, int end, int l, int r, int val)
{
    if (start > r || end < l) return;
    if (start >= l && end <= r)
    {
        tree[node] += (end - start + 1) * val;
        lazy[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1] + ((end - start + 1) * lazy[node]);
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 1; i <= q; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            int val;
            cin >> val;
            update(1, 0, n - 1, l - 1, r - 1, val);
        }
        else
        {
            cout << query(1, 0, n - 1, l , r) << endl;
        }
    }
    return 0;
}
