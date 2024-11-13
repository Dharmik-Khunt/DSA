#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//performs BFS and checks for cycles
bool hasCycleBFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q; // pair<current_node, parent_node>
    q.push({start, -1}); // Start node has no parent
    visited[start] = true;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node}); // Mark as visited and set parent
            } else if (neighbor != parent) {
                // If visited and not the parent, cycle found
                return true;
            }
        }
    }
    return false;
}

//initiates BFS for each component of the graph to ensure all vertices are checked.
bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleBFS(i, adj, visited)) {
                return true; // Cycle found
            }
        }
    }
    return false; // No cycle found
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[1].push_back(3); // This creates a cycle
    adj[3].push_back(1); // Undirected

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}