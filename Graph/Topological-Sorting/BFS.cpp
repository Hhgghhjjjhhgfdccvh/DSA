#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);
    vector<vector<int>> adj(n);

    // Build adjacency list and in-degree array
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }

    queue<int> q;
    int count = 0;

    // Push all nodes with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;  // Count processed nodes

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If we processed all nodes, no cycle exists
    return count != n;  // If count < n, there is a cycle
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};  // Cycle present
    int n = 4;
    
    if (hasCycle(n, edges)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}
