#include<iostream>
#include<vector>
using namespace std;

const int N=1e5+10;
vector<vector<int>>g(N);
int depth[N];

void dfs(int ver,int par)
{
    for(auto &child: g[ver])
    {
        if(child==par) continue;
        depth[child]=depth[ver]+1;
        dfs(child,ver);
    }
}
int main()
{
    int n,e;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    int max_depth=-1,max_depth_node=0;
    for(int i=1; i<=n; i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    dfs(max_depth_node,-1);
    max_depth=-1;
    for(int i=1; i<=n; i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
        }
    }
    cout<<max_depth<<endl;
    return 0;
}
/* Test Case:
14
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
12 14
Output: 9
*/
