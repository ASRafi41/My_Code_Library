#include <bits/stdc++.h>
using namespace std;

// Floyd-Warshall Algorithm - Used to find the shortest paths between all pairs of nodes in a graph.
// Time Complexity = V * V * V

const int N = 510, INF = 1e9 + 10;
int dp[N][N];
int n, m;

void floydWarshall()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dp[i][k] < INF && dp[k][j] < INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) // reset
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dp[x][y] = wt;
        // dp[y][x] = wt;
    }

    floydWarshall();
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] == INF) cout << "i ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
