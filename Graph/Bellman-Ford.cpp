#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int source, destination, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int E, int source)
{
    vector<int> distance(V + 1, INT_MAX);
    vector<int> predecessor(V + 1, -1);

    distance[source] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
            }
        }
    }

    // Print the shortest paths
    for (int i = 1; i <= V; i++)
    {
        cout << "{" << source << " -> " << i << "} => ";
        int current = i;
        vector<int> path;
        while (current != -1)
        {
            path.push_back(current);
            current = predecessor[current];
        }
        cout << "Path -> ";
        for (int j = path.size() - 1; j >= 0; j--)
        {
            cout << path[j] << " ";
        }
        cout << " => Cost = " << distance[i] << endl;
    }
}

int main()
{
    int V; // Number of vertices
    int E; // Number of edges
    cin >> V >> E;

    vector<Edge> edges;
    for(int i = 0; i < E; i++)
    {
        int u, v, cost; cin >> u >> v >> cost;
        if(u > v) swap(u, v); // <===
        edges.push_back({u, v, cost});
    }

    int source = 1; // Source vertex

    bellmanFord(edges, V, E, source);

    return 0;
}
