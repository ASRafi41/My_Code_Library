/* DSU Applications:
1) Cycle detection
2) Connected Components in graph
3) MST(Minimum Spanning Tree) */
#include <bits/stdc++.h> //=> O(1)
using namespace std;

const int N = 1e5 + 10;
int par[N];
int Size[N];

int Find(int v) // returns the representative of the set that contains the element v
{
    if (par[v] == v) return v;
    return par[v] = Find(par[v]); // Path Compression
}

void Union(int u, int v) // merges the two specified sets(u & v)
{
    int repU = Find(u);
    int repV = Find(v);
    if (repU != repV)
    {
        if (Size[repU] < Size[repV]) swap(repU, repV); // Union by size
        par[repV] = repU;
        Size[repU] += Size[repV];
    }
}

int get_size(int i)
{
    return Size[Find(i)];
}

void numberOfConnectedComponents(int n)
{
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Find(i) == i) ++ct;
    }
    cout << ct << endl;
}

void build(int n)
{
    for (int i = 0; i <= n; i++) 
    {
        par[i] = i;
        Size[i] = 1;
    }
}

int main()
{
    int u, v, tc, n, k;
    cin >> n >> k;
    
    build(n); // Create a new set

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
    
    numberOfConnectedComponents(n); // Count Connected Components

    return 0;
}
