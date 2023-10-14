/* DSU Applications:
1) Cycle detection
2) Connected Components in graph
3) MST(Minimum Spanning Tree) */
#include <bits/stdc++.h> //=> O(1)
using namespace std;

const int N = 1e5 + 10;
int par[N];
int Size[N];
multiset<int> grpSize;

int Find(int v) // returns the representative of the set that contains the element v
{
    if (par[v] == v) return v;
    return par[v] = Find(par[v]); // Path Compression
}
void margeGrpSize(int repU, int repV)
{
    grpSize.erase(grpSize.find(Size[repU]));
    grpSize.erase(grpSize.find(Size[repV]));

    grpSize.insert(Size[repU] + Size[repV]);
}
void Union(int u, int v) // merges the two specified sets(u & v)
{
    int repU = Find(u);
    int repV = Find(v);
    if (repU != repV)
    {
        if (Size[repU] < Size[repV]) swap(repU, repV); // Union by size
        par[repV] = repU;
        //margeGrpSize(repU, repV);
        Size[repU] += Size[repV];
    }
}
int main()
{
    int u, v, tc, n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) // Create a new set
    {
        par[i] = i;
        Size[i] = 1;
        //grpSize.insert(1);
    }
    bool cycle = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> u >> v;
        /* //Finding Cycle
        if(Find(u)==Find(v)) cycle=1;   //Cycle is Found;
        else Union(u, v); */
        Union(u, v);
    }
    // if(cycle) cout<<"Found Cycle";

    /* //Count Connected Components
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Find(i) == i) ++ct;
    }
    cout << ct << endl; */
    return 0;
}
