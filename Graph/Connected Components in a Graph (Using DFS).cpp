//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl      '\n'
#define _ASRafi_  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
const int N=1e5+10;
vector<ll>g[N];
bool isVis[N];

vector<vector<ll>>cCom;
vector<ll>temp_cCom;

void dfs(ll vertex)
{
    if(isVis[vertex]) return;
    temp_cCom.push_back(vertex);
    isVis[vertex]=true;
    for(auto &child: g[vertex])
    {
        dfs(child);
    }
}
int main() {
    _ASRafi_
    ll n,e,v1,v2;
    cin>>n>>e;
    for(ll i=0;i<e;i++)
    {
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(ll i=1;i<=n;i++)
    {
        if(isVis[i]) continue;
        temp_cCom.clear();
        dfs(i);
        cCom.push_back(temp_cCom);
    }
    cout<<cCom.size()<<endl;
//    for(auto &i: cCom)
//    {
//        for(auto &j: i) cout<<j<<" ";
//        cout<<endl;
//    }
	return 0;
}
