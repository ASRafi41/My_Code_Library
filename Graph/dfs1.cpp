//Time Complexity-> O(n+e)
#include<iostream>
#include<vector>
using namespace std;
#define ll long long

const ll N=1e5+10;
vector<ll> g[N], height(N), depth(N);
bool vis[N];
int Par[N];

void dfs(ll vertex,ll par=-1)
{
    /** Take action on vertex after entering
     *  the vertex.
     **/

    //if(vis[child]) return;
    vis[vertex]=true;
    Par[vertex] = par;
    //bool isLoopExists = false; //<=Use For Finding Cycle
    for(auto &child: g[vertex])
    {
        /** Take action on child before entering
         *  the child node.
         **/
        
        if(vis[child]) continue;
        dfs(child, vertex);

        /* => Use for Finding Cycle:
            if(vis[child] && child == par) continue;
            if(vis[child]) return true;
            isLoopExists |= dfs(child, vertex);
        */
        /* => Use for Tree(No need Visited arrar):
            if(child == par) continue;
            depth[child] = depth[vertex]+1;
            dfs(child, vertex);
            height[vertex] = max(height[vertex], height[child]+1);
        */
        /** Take action on child
         *  after exiting child node.
         **/
    }
    /** Take action on vertex before
     *  exiting the vertex.
     **/
}
int main()
{
    ll n,e,v1,v2;   ///n=vertex, e=edge;
    cin>>n>>e;
    for(ll i=0;i<e;i++)
    {
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}

/*
Test Case:
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
