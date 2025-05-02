// Problem: https://www.spoj.com/problems/LCA/en/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 3e5 + 7;
vector<int> g[N];

struct LCA {
    int table[N + 1][21];
    int level[N];

    void dfs(int v, int par = -1, int dep = 0) {
        table[v][0] = par;
        level[v] = dep;
        for (int i = 1; i <= 20; i++) {
            if (table[v][i - 1] != -1) {
                table[v][i] = table[table[v][i - 1]][i - 1];
            }
        }
        for (auto &child : g[v]) {
            if (child == par) continue;
            dfs(child, v, dep + 1);
        }
    }
    void build(int n, int root = 1) { //=> O(N * log N)
        for (int i = 0; i <= n; i++) {
            level[i] = 0;
            for (int j = 0; j <= 20; j++) table[i][j] = -1;
        }
        dfs(root);
    }

    int query(int a, int b) { //=> O(log N)
        if (level[a] < level[b]) swap(a, b);
        for (int i = 20; i >= 0; i--) {  // a and b come to the same level
            if (table[a][i] != -1 && level[table[a][i]] >= level[b])
                a = table[a][i];
        }
        if (a == b) return a; 
        for (int i = 20; i >= 0; i--) {
            if (table[a][i] != -1 && table[a][i] != table[b][i]) {
                a = table[a][i], b = table[b][i];
            }
        }
        return table[a][0];
    }
    int dist(int u, int v) { // distance between two node
        int l = query(u, v);
        return level[u] + level[v] - (level[l] << 1);
    }
    int kth(int u, int k) {
        for (int i = 0; i <= 20; i++)
            if (k & (1 << i)) u = table[u][i];
        return u;
    }
    int findKth(int u, int v, int k) { // kth node from u to v, 0th node is u
        int l = query(u, v);
        int d = level[u] + level[v] - (level[l] << 1);
        if (level[l] + k <= level[u]) return kth(u, k);
        k -= level[u] - level[l];
        return kth(v, level[v] - level[l] - k);
    }
} lca;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear(); // <== reset
    for (int i = 1; i <= n; i++) {
        int x, u; cin >> x;
        while (x--) {
            cin >> u;
            g[u].push_back(i);
            g[i].push_back(u);
        }
    }
    lca.build(n, 1); // <==
    int q; cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}
