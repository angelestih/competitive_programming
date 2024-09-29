#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;


// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    // Add edge from vertex s to t, and t to s
    adj[s].push_back(t); 

    adj[t].push_back(s);
}

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited)
{
    queue<int> q;

    visited[s] = true;

    q.push(s);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

}





// Perform BFS for the entire graph
void bfsDisconnected(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false); // Not visited

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited);
        }
    }
}

int main() 
{
    int V = 6; // Number of vertices

    vector<vector<int>> adj(V); // Adjacency list

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);  

    // Perform BFS traversal for the entire graph
    bfsDisconnected(adj);

    return 0;
}