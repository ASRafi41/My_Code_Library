#include <iostream>
#include <vector>
#include <set>
using namespace std;
//=> Time Complexity=(V+ E*Log(V))
const int N = 1e5 + 10, INF = 1e9 + 7;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
vector<bool> vis(N);

void dijkstra(int s)
{
    multiset<pair<int, int>> st;
    st.insert({0, s});
    dist[s] = 0;

    while (st.size())
    {
        int u = (st.begin())->second;
        // int u_w=(st.begin())->first;
        st.erase(st.begin());
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &child : g[u])
        {
            int v = child.first;
            int v_w = child.second;
            if (dist[u] + v_w < dist[v])
            {
                dist[v] = dist[u] + v_w;
                st.insert({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    // for(int i=1;i<=6;i++)
    // {
    //     cout<<i<<"=> ";
    //     for(auto &j: g[i]) cout<<j.first<<" "<<j.second<<", ";
    //     cout<<endl;
    // }
    dijkstra(1);
    cout << "Distrance=> ";
    for (int i = 1; i <= 6; i++)
        cout << dist[i] << ", ";
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

Output:  Distrance=> 0, 1, 3, 3, 2, 4,
*/