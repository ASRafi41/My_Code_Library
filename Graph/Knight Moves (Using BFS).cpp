#include <bits/stdc++.h>
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define endl '\n'
using namespace std;

const int kx[] = {-2, -2, -1, -1, +1, +1, +2, +2}; /// knight's move
const int ky[] = {-1, +1, -2, +2, -2, +2, -1, +1}; /// knight's move
const int N = 1e3 + 10;

bool vis[N][N];
int level[N][N];

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8 && (!vis[x][y]);
}
int bfs(string source, string dest)
{
    int sourceX = source[0] - 'a';
    int sourceY = source[1] - '1';
    int destX = dest[0] - 'a';
    int destY = dest[1] - '1';
    
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0; 

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int childX = kx[i] + x;
            int childY = ky[i] + y;
            if (isValid(childX, childY))
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
    }
    return level[destX][destY];
}
void reset()
{
    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
}
int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int ans = bfs(s1, s2);
        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves.\n";
        reset();
    }
    return 0;
}
