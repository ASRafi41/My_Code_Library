// problem link: https://cses.fi/problemset/task/2134/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
 
const int N = 2e5 + 3, LG = 18;

struct Segment_Tree { // 1'base
    ll t[2 * N];
    auto merge(auto &l, auto &r) { // <==
        return max(l, r);
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
        ll ans = 0;
        for (; L <= R; L >>= 1, R >>= 1) {
            if (L & 1) ans = merge(ans, t[L++]);
            if (!(R & 1)) ans = merge(ans, t[R--]);
        }
        return ans;
    }
} st1;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for (auto &v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--)
        if (par[u][k] != par[v][k])
            u = par[u][k], v = par[v][k];
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0); // <==
    for (int i = 0; i <= LG; i++)
        if (k & (1 << i))
            u = par[u][i];
    return u;
}

int T, head[N], st[N], en[N];
void dfs_hld(int u) {
    st[u] = ++T;
    for (auto v : g[u]) {
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v);
    }
    en[u] = T;
}
int n;
ll query_up(int u, int v) {
    ll ans = 0;
    while (head[u] != head[v]) {
        // ans += st1.query(1, 1, n, st[head[u]], st[u]);
        ans = max(ans, st1.query(1, 1, n, st[head[u]], st[u]));
        u = par[head[u]][0];
    }
    // ans += st1.query(1, 1, n, st[v], st[u]);
    ans = max(ans, st1.query(1, 1, n, st[v], st[u]));
    return ans;
}
ll query(int u, int v) {
    int l = lca(u, v);
    ll ans = query_up(u, l);
    if (v != l) {
        // ans += query_up(v, kth(v, dep[v] - dep[l] - 1));
        ans = max(ans, query_up(v, kth(v, dep[v] - dep[l] - 1)));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q; cin >> n >> q;
    int val[n + 1];
    for(int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Build
    dfs(1);
    head[1] = 1;
    dfs_hld(1);
    for(int u = 1; u <= n; u++) {
        st1.update(1, 1, n, st[u], val[u]);
    }

    short type;
    while (q--) {
        cin >> type;
        if(type == 1) {
            int s, x; cin >> s >> x;
            st1.update(1, 1, n, st[s], x);
        }
        else {
            int a, b; cin >> a >> b;
            cout << query(a, b) << " ";
        }
    }
    cout << endl;
    return 0;
}
