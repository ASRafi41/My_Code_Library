#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct HopcroftKarp { // O(sqrt(V) * E * log V)
  static const int inf = 1e9;
  int n;
  vector<int> l, r, d;
  vector<vector<int>> g;
  HopcroftKarp(int _n, int _m) {
    n = _n;
    int p = _n + _m + 1;
    g.resize(p);
    l.resize(p, 0);
    r.resize(p, 0);
    d.resize(p, 0);
  }
  void add_edge(int u, int v) { // 1'base
    g[u].push_back(v + n); // right id is increased by n, so is l[u]
  }
  bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
      if (!l[u]) d[u] = 0, q.push(u);
      else d[u] = inf;
    }
    d[0] = inf;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (d[r[v]] == inf) {
          d[r[v]] = d[u] + 1;
          q.push(r[v]);
        }
      }
    }
    return d[0] != inf;
  }
  bool dfs(int u) {
    if (!u) return true;
    for (auto v : g[u]) {
      if(d[r[v]] == d[u] + 1 && dfs(r[v])) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    d[u] = inf;
    return false;
  }
  int maximum_matching() {
    int ans = 0;
    while (bfs()) {
      for(int u = 1; u <= n; u++) if (!l[u] && dfs(u)) ans++;
    }
    return ans;
  }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    auto isPrefectSquare = [&](ll val) -> bool {
        return ll(sqrtl(val)) * ll(sqrtl(val)) == val;
    };

    HopcroftKarp hk(n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            if(isPrefectSquare(v[i] + j)) {
                hk.add_edge(i + 1, j);
            }
        }
    }
    cout << (hk.maximum_matching() == n ? "YES" : "NO") << endl;
    return 0;
}
// problem link: https://codeforces.com/gym/106059/problem/J
