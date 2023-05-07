//Time Complexity=> O(vertex+edge)
//Find vertex Level
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5+10;
vector<int>g[N];
bool vis[N];
int level[N];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;

    while(!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        for(auto &child: g[cur_v])
        {
            if(vis[child]) continue;
            q.push(child);
            vis[child]=1;
            level[child]=level[cur_v]+1;
        }
    }
}
int main()
{
    int n,e;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": "<<level[i]<<endl;
    }
    return 0;
}
/*Test Case:
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

Output:
1: 0
2: 1
3: 1
4: 2
5: 2
6: 3
7: 3
8: 3
9: 3
10: 3
11: 4
12: 4
13: 1
*/
