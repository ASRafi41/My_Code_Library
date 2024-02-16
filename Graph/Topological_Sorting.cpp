#include<bits/stdc++.h>
using namespace std;

// topological sort means linear ordering of values such that if there is an edge u -> v,
// u appears before v in that ordering.

/**
 *  5 -> 0 <- 4
 *  => 5 4 0
 *  5 -> 0 edge in graph and in array 5 appears before 0,
 *  same for 4 -> 0 edge.
 *  It is applicable only for DAG, Directed Acyclic Graph.
 *  Directed because it tells about the ordering
 *  If cyclic graph, like 2 -> 3 -> 4 ->...2
 *  Array: [2, 3, 4] for edge 4 -> 2, 4 can never appear before 2,
 *  So only applicable for acyclic graph
 **/

// ------ Using DFS ------
void topoSortDFS(int node, stack<int> &topo, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;

    for (auto i : adj[node])
    {
        if (!vis[i]) topoSortDFS(i, topo, vis, adj);
    }

    topo.push(node);
}

void topoSortDFS(int v, vector<vector<int>> &adj)
{
    stack<int> topo;
    vector<int> vis(v + 1, 0);

    for (int i = 0; i <= v; i++)
    {
        if (!vis[i]) topoSortDFS(i, topo, vis, adj);
    }

    // Print
    while (!topo.empty())
    {
        cout << topo.top() << " ";
        topo.pop();
    }
    cout << endl;
}

// ------ Using BFS (Kahn's Algorithm) -------
void topoSortBFS(int v, vector<vector<int>> &adj)
{
    queue<int> nodes;
    vector<int> inDeg(v + 1, 0);
    vector<int> ans; 
    for (int i = 0; i <= v; i++)
    {
        for (int j : adj[i]) inDeg[j]++;
    }

    for (int i = 0; i <= v; i++)
    {
        if (inDeg[i] == 0) nodes.push(i);
    }

    while (!nodes.empty())
    {
        int n = nodes.front();
        ans.push_back(n);
        nodes.pop();

        for (int i : adj[n])
        {
            inDeg[i]--;
            if (inDeg[i] == 0) nodes.push(i);
        }
    }

    // If Topological Sort does not exist then the vector size will be less than the number of vertex size
    if(ans.size() < v) cout << "Topological Sort does not exist for this graph :)" << endl;
    else
    {
        for (auto &i: ans) cout << i << " ";
        cout << endl;
    }
}

int32_t main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> g(vertex + 1);
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    cout << "Topological Sort of the given graph: \n";
    
    topoSortDFS(vertex, g);
    topoSortBFS(vertex, g);

    return 0;
}

/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
Topological Sort of the given graph: 5 4 2 3 1 0
*/