#include<bits/stdc++.h>
typedef long long  ll;
#define endl       '\n'
#define F          first
#define S          second
#define pb         push_back
#define ppb        pop_back
#define pll        pair<ll,ll>
#define yes        cout<<"YES\n"
#define no         cout<<"NO\n"
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define coutall(v) for(auto &it: v)cout<<it<<' ';cout<<endl;
#define _ASRafi_   ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

//const double pi=2*acos(0.0);
const ll N=1e5+10, mod=1e9+7;

vector<pair<int,int>>g[N];
vector<int>level(N,INT_MAX);
void bfs()
{
    deque<int>q;
    q.pb(1);
    level[1]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop_front();
        for(auto &child: g[par])
        {
            int u=child.F, w=child.S;
            if(level[par]+w<level[u])
            {
                level[u]=level[par]+w;
                if(w==0) q.push_front(u);
                else q.push_back(u);
            }
        }
    }
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll x,y,w; cin>>x>>y>>w;
        if(x==y) continue;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }
    bfs();
    for(ll i=1;i<=n;i++)
    {
        cout<<level[i]<<", ";
    }
    return 0;
}
