#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl      '\n'
#define _ASRafi_  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);

const int N=1e5+10;
vector<vector<ll>>g(N);
int subtree_sum[N];
int even_ct[N];

void dfs(ll vertex,ll par)
{
    if(vertex%2==0) even_ct[vertex]++;
    subtree_sum[vertex]+=vertex;
    for(auto &child: g[vertex])
    {
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
    }
}
int main() {
    _ASRafi_
	ll n,e;
	cin>>n;
	for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);  //<=Pre-Computation

//    for(ll i=1;i<=n;i++)
//    {
//        cout<<subtree_sum[i]<<" "<<even_ct[i]<<endl;
//    }

    ll q;
    cin>>q;
    while(q--)
    {
        ll v; cin>>v;
        cout<<subtree[v]<<" ";
        cout<<even_ct[v]<<endl;
    }
	return 0;
}
/*
Test Case 1:
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
...(add input query input and v)
/*
