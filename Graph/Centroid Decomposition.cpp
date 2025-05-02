// Problem link: https://codeforces.com/problemset/problem/342/E
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1e5 + 7, INF = 1e9 + 3;
vector<int> g[N];

struct LCA {
    static const int lg = 20;
    int table[N][lg + 1];
    int level[N];

    void dfs(int v, int par = -1, int dep = 0) {
        table[v][0] = par;
        level[v] = dep;
        for (int i = 1; i <= lg; i++) {
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
            for (int j = 0; j <= lg; j++) table[i][j] = -1;
        }
        dfs(root);
    }

    int findLCA(int a, int b) { //=> O(log N)
        if (level[a] < level[b]) swap(a, b);
        for (int i = lg; i >= 0; i--) {  // a and b come to the same level
            if (table[a][i] != -1 && level[table[a][i]] >= level[b])
                a = table[a][i];
        }
        if (a == b) return a; 
        for (int i = lg; i >= 0; i--) {
            if (table[a][i] != -1 && table[a][i] != table[b][i]) {
                a = table[a][i], b = table[b][i];
            }
        }
        return table[a][0];
    }
    int dist(int u, int v) { // distance between two node
        int l = findLCA(u, v);
        return level[u] + level[v] - (level[l] << 1);
    }
    int kth(int u, int k) {
        for (int i = 0; i <= lg; i++)
            if (k & (1 << i)) u = table[u][i];
        return u;
    }
    int findKth(int u, int v, int k) { // kth node from u to v, 0th node is u
        int l = findLCA(u, v);
        int d = level[u] + level[v] - (level[l] << 1);
        if (level[l] + k <= level[u]) return kth(u, k);
        k -= level[u] - level[l];
        return kth(v, level[v] - level[l] - k);
    }
} lca;

struct Centroid_Decomposition {
    bool removed[N];
    int subsize[N], centParent[N];

    // 1) compute sizes of all subtrees in current component
    int dfs_size(int u, int p) {
        subsize[u] = 1;
        for (int v : g[u]) {
            if (v == p || removed[v]) continue;
            subsize[u] += dfs_size(v, u);
        }
        return subsize[u];
    }
    // 2) find centroid: walk until no child‐subtree > total/2
    int find_centroid(int u, int p, int total) {
        for (int v : g[u]) {
            if (v == p || removed[v]) continue;
            if (subsize[v] > total / 2)
                return find_centroid(v, u, total);
        }
        return u;
    }
    // 3) recursively decompose and build centroid‐tree
    void decompose(int u, int p) {
        int n = dfs_size(u, -1);
        int cent = find_centroid(u, -1, n);
        removed[cent] = true;
        centParent[cent] = p;
        // recurse on each subtree
        for (int v : g[cent]) {
            if (removed[v]) continue;
            decompose(v, cent);
        }
    }

    int ans[N];
    void build(int n, int root) {
        for(int i = 0; i <= n; i++) {
            ans[i] = INF;
            removed[N] = false;
            subsize[N] = centParent[N] = 0;
        }
        decompose(root, -1);
    }
    void update(int u) { // O(log N)
        int cur = u;
        while (cur != -1) {
            // process contribution between u and cur
            ans[cur] = min(ans[cur], lca.dist(u, cur));
            // end
            cur = centParent[cur]; // jump
        }
    }
    int query(int u) { // O(log N)
        int cur = u, mn = INF;
        while (cur != -1) {
            // process contribution between u and cur
            mn = min(mn, ans[cur] + lca.dist(u, cur));
            // end
            cur = centParent[cur]; // jump
        }
        return mn;
    }
} cd;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lca.build(n, 1); // <==
    cd.build(n, 1); // <==
    cd.update(1); // initially red node at 1
    while(q--) {
        int t, u;
        cin >> t >> u;
        if(t == 1) {
            cd.update(u);
        }
        else {
            cout << cd.query(u) << endl;
        }
    }
    return 0;
}
