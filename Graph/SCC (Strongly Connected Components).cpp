// Kosaraju Algorithm -> O(n + e)
// Only for Directed Graph
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define _ASRafi__ ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);

const int N = 1e5 + 7;
vector<int> g[N], r[N], comp[N]; // 1'Base Indexing
bool vis[N];
stack<int> st;
int u, v, n, m, numOfComp;

void dfs(int i)
{
    vis[i] = 1;
    for(auto &j: g[i])
    {
        if(vis[j]) continue;
        dfs(j);
    }
    st.push(i);
}
void dfs2(int i)
{
    vis[i] = 1;
    comp[numOfComp].push_back(i);

    for(auto &j: r[i])
    {
        if(vis[j]) continue;
        dfs2(j);
    }
}
void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        dfs(i);
    }
    memset(vis, 0, sizeof vis);
    numOfComp = 0;
    while(!st.empty())
    {
        // cout << st.top() << endl;
        int x = st.top();
        if(!vis[x]) 
        {
            ++numOfComp;
            dfs2(x);
        }
        st.pop();
    }
    for(int i = 1; i <= n; i++)
    {
        if(comp[i].size() == 0) continue;
        cout << i << "=> ";
        for(auto &j: comp[i]) cout << j << ", ";
        cout << endl;
    }
    return;
}
void reset()
{
    for(int i = 0; i <= n; i++)
    {
        g[i].clear();
        r[i].clear();
        comp[i].clear();
        vis[i] = 0;
    }
}
int main()
{
    _ASRafi__;
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
