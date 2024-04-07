#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// Dijkstra's Algorithm - Used to find the shortest path between nodes in a graph with non-negative edge weights.
// Time Complexity = (V + E) * Log(V)

const ll INF = LLONG_MAX;
vector<vector<pair<ll, ll>>> g;

void dijkstra(ll s, vector<ll> &d, vector<ll> &p)
{
    ll n = g.size();
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);

    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    
    while (!q.empty())
    {
        auto [d_v, v] = q.top();
        q.pop();
        if (d_v != d[v]) continue;
        for (auto &[to, len] : g[v])
        {
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

vector<ll> restore_path(ll s, ll dest, vector<ll> const &p)
{
    vector<ll> path;
    for (auto v = dest; v != s && p[v] != -1; v = p[v]) path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, source = 1;
    cin >> n >> m;
    g.assign(n + 1, {}); // <===
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // -- Print List --
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << "=> ";
    //     for (auto &j : g[i]) cout << '{' << j.first << ", " << j.second << "}, ";
    //     cout << endl;
    // }

    vector<ll> dist, Paths;
    dijkstra(source, dist, Paths); // source 1

    cout << "-> Distance <-" << endl;
    for (int i = 1; i <= n; i++) cout << source << " to " << i << " => " << dist[i] << endl;

    cout << "\n-> Source to Destination Path <- " << endl;
    int dest = n; // <==
    auto path = restore_path(source, dest, Paths);
    if(path.back() != dest)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < path.size(); i++) cout << path[i] << (i + 1 == path.size() ? "\n" : " -> ");

    return 0;
}

/*Test Case:
6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2

Output:  Distance => 0, 1, 3, 3, 2, 4,
*/
