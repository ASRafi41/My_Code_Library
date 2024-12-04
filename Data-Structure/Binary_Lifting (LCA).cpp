#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 3e5 + 7;
vector<vector<int>> g(N);
int table[N + 1][22];
int level[N];
int tin[N], tout[N];
// int minLen[N + 1][22], maxLen[N + 1][22]; // maximum ans minimum weight of a graph
int n, lg, Time = 0, INF = 1e9 + 10;

void dfs(int v, int par = -1, int dep = 0) { // ,int mn = INF, int mx = -1
    tin[v] = ++Time;    // for find is_ancestor
    table[v][0] = par;
    level[v] = dep;
    // minLen[v][0] = mn, maxLen[v][0] = mx;
    for (int i = 1; i <= lg; i++) {
        if (table[v][i - 1] != -1) {
            table[v][i] = table[table[v][i - 1]][i - 1];
            // minLen[v][i] = min(minLen[v][i - 1], minLen[table[v][i - 1]][i - 1]);
            // maxLen[v][i] = max(maxLen[v][i - 1], maxLen[table[v][i - 1]][i - 1]);
        }
    }
    for (auto &child : g[v]) {
        if (child == par) continue;
        dfs(child, v, dep + 1);
        // dfs(child.first, v, dep + 1, child.second, child.second); //for max & min 
    }
    tout[v] = ++Time;
}

void lca_build(int root = 1) { //=> O(n * logn)
    dfs(root);
}

int lca_query(int a, int b) { //=> O(logn)
    if (level[a] < level[b]) swap(a, b);
    // int dis = level[a] - level[b], mx = 0;
    // while(dis) {
    //     int i = log2l(dis);
    //     mx = max(mx, maxLen[a][i]);
    //     a = table[a][i], dis -= (1 << i);
    // }
    for (int i = lg; i >= 0; i--) {  //a and b come to the same level
        if (table[a][i] != -1 && level[table[a][i]] >= level[b])
            a = table[a][i];
    }
    
    if (a == b) return a; // return mx;

    for (int i = lg; i >= 0; i--) {
        if (table[a][i] != -1 && table[a][i] != table[b][i]) {
            // mx = max(mx, maxLen[a][i]);
            // mx = max(mx, maxLen[b][i]);
            a = table[a][i], b = table[b][i];
        }
    }
    // mx = max(mx, maxLen[a][0]);
    // mx = max(mx, maxLen[b][0]);
    return table[a][0]; // return mx;
}

int dist(int u, int v) { // distance between two node
    int l = lca_query(u, v);
    return level[u] + level[v] - (level[l] << 1); // level[l]*2
}

int kth(int u, int k) {
    for (int i = 0; i <= lg; i++)
        if (k & (1 << i)) u = table[u][i];
    return u;
}

int findKth(int u, int v, int k) { // kth node from u to v, 0th node is u
    int l = lca_query(u, v);
    int d = level[u] + level[v] - (level[l] << 1);
    if (level[l] + k <= level[u]) return kth(u, k);
    k -= level[u] - level[l];
    return kth(v, level[v] - level[l] - k);
}

bool is_ancestor(int u, int v) { // u is an ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void reset() {
    lg = log2l(n) + 1;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        level[i] = 0;
        for (int j = 0; j <= lg; j++) table[i][j] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    reset(); // <===

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lca_build(1);

    // Querys
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << '\n';
    }
    return 0;
}
