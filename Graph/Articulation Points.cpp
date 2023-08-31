// Articulation Points Using Tarjan's Algorithm => O(N + M)
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 3e5 + 9;

int T, low[N], dis[N], art[N];
vector<int> g[N];
int n, m;

void dfs(int u, int pre = 0)
{
    low[u] = dis[u] = ++T;
    int child = 0;
    for (auto &v : g[u])
    {
        if (!dis[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dis[u] && pre != 0) art[u] = 1;
            ++child;
        }
        else if (v != pre) low[u] = min(low[u], dis[v]);
    }
    if (pre == 0 && child > 1) art[u] = 1;
}
void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1); // for single connected component

    cout << "Articulation Points are : ";
    for (int i = 1; i <= n; i++)
    {
        if(art[i]) cout << i << " ";
    }
    return;
}
void reset()
{
    T = 0;
    for (int i = 0; i <= n; i++) 
        low[i] = dis[i] = art[i] = 0, g[i].clear();
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
        if(tc != t) reset();
    }
    return 0;
}
