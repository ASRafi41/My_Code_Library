#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl      '\n'
#define _ASRafi_  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);

const int N=1e5+10;
vector<vector<ll>>t(N);
vector<ll>height(N),depth(N);

void dfs(ll vertex,ll par)
{
    for(auto &child: t[vertex])
    {
        if(child==par) continue;
        depth[child]=depth[vertex]+1; //<- Depth
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1); //<- Height
    }
}
int main()
{
    _ASRafi_
	ll n,e;
	cin>>n;
	for(ll i=0;i<n-1;i++)
    {
        ll x,y; cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1,-1);
    for(ll i=1;i<=n;i++)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
	return 0;
}
/* Test Case 1:
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/
