#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+10;
vector<vector<ll>>g(N);
vector<bool>isVis(N);

bool dfs(ll vertex, ll par)
{
    isVis[vertex]=true;
    bool isLoopExists=false;
    for(auto &child: g[vertex])
    {
        if(isVis[child] && child==par) continue;
        if(isVis[child]) return true;
        isLoopExists |= dfs(child,vertex);
    }
    return isLoopExists;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    for(ll i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isLoopExists=false;
    for(ll i=1;i<=n;i++)
    {
        if(isVis[i]) continue;
        if(dfs(i,0))
        {
            isLoopExists=true;
            break;
        }
    }
    cout<<isLoopExists<<endl;
    return 0;
}
/* Test Case 1:
8 5
1 2
2 3
2 4
3 5
6 7
Output: false(0)

Test Case 2:
8 6
1 2
2 3
2 4
3 5
6 7
1 5
Output: true(1)

*/
