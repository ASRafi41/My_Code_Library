#include<bits/stdc++.h>
#define endl       '\n'
typedef long long  ll;
using namespace std;

const int N = 1000 + 10;
int g[N][N];
bool vis[N][N];
ll ans, allVis;

void dfs(int i, int j, int row, int col)
{
    if (i < 0 || j < 0 || i >= row || j >= col) return;
    if (g[i][j] == 0 || vis[i][j]) return;

    ++allVis;
    ans += g[i][j];
    vis[i][j] = 1;

    dfs(i - 1, j, row, col); // up
    dfs(i + 1, j, row, col); // down
    dfs(i, j - 1, row, col); // left
    dfs(i, j + 1, row, col); // right
}
void reset()
{
    // memset(g, 0, sizeof(g));
    // memset(vis, 0, sizeof(vis));
    allVis = 0;
}
void solve()
{
    reset();

    int n, m;
    ll c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && g[i][j] != 0)
            {
                ans = 0;
                dfs(i, j, n, m);
                c = max(ans, c);
            }
            if (allVis == n * m) break;
        }
    }
    cout << c << endl;
    return;
}
int main()
{
    int tc=1;
    cin>>tc;
    while(tc--) solve();
    return 0;
}
