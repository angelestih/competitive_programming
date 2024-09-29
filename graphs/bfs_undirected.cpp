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

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    vector<bool> visited(V, false);

    cout << "BFS starting from 0: \n" ;

    bfs(adj, 0, visited);

    return 0;

}