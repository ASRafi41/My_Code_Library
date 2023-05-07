#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; //=>O(N)
vector<int> g[N];
int Par[N];

void dfs(int vertex, int par)
{
    Par[vertex] = par;
    for (auto &child : g[vertex])
    {
        if (child == par) continue;
        dfs(child, vertex);
    }
}
vector<int> path(int v)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = Par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, e;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    int x, y;
    cin >> x >> y;
    vector<int> path1, path2;
    path1 = path(x);
    path2 = path(y);
    int LCA = -1;
    for (int i = 0; i < min(path1.size(), path2.size()); i++)
    {
        if (path1[i] != path2[i]) break;
        LCA = path1[i];
    }

    //    for(int i=0;i<path1.size();i++) cout<<path1[i]<<" ";
    //    cout<<endl;
    //    for(int i=0;i<path2.size();i++) cout<<path2[i]<<" ";
    //    cout<<endl;

    cout << LCA << endl;
    return 0;
}

/* Test Case:
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 11 <-find this 2 vertex LCA
Output: 4
*/
