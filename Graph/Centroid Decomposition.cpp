// Problem: https://cses.fi/problemset/task/2080
// Centroid decomposition => O(N * logN)
// Applications: For all possible path type problem

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 2e5 + 3;
int n, mx_depth;
vector<int> g[N];
int subtree[N];
bitset<N> processed = 0;

// Function to compute subtree sizes rooted at each node
int get_subtree_sizes(int node, int parent = 0) {
    subtree[node] = 1;
    for (int i : g[node]) {
        if (!processed[i] && i != parent) {
            subtree[node] += get_subtree_sizes(i, node);
        }
    }
    return subtree[node];
}

// Function to find the centroid of the subtree
int get_centroid(int desired, int node, int parent = 0) {
    for (int i : g[node]) {
        if (!processed[i] && i != parent && subtree[i] >= desired)
        return get_centroid(desired, i, node);
    }
    return node;
}

ll ans, k;
int cnt[N];

void get_cnt(int node, int parent, bool filling, int depth = 1) {
    // edit here
    if(depth > k) return;
    if(filling) cnt[depth]++;
    else ans += cnt[k - depth];
    //
    
    mx_depth = max(mx_depth, depth);
    for (int i : g[node]) {
        if (!processed[i] && i != parent) {
            get_cnt(i, node, filling, depth + 1);
        }
    }
}

// Centroid decomposition function
void centroid_decomp(int node = 1) {
    int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
    processed[centroid] = true;
    mx_depth = 0;

    // Updating counters for each child of the centroid
    auto &Cur = g[centroid];
    for(int i = 0; i < Cur.size(); i++) {
        if(!processed[Cur[i]]) {
            get_cnt(Cur[i], centroid, false); // calculate
            if(i + 1 < Cur.size()) get_cnt(Cur[i], centroid, true); // update
        }
    }
    // edit here
    fill(cnt + 1, cnt + mx_depth + 1, 0); // reset
    //

    for(int i : g[centroid]) {
        if (!processed[i]) centroid_decomp(i);
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    cnt[0] = 1; // for k length
    centroid_decomp();
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
