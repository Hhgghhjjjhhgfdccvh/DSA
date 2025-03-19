









// 684. Redundant Connection
// Solved
// Medium
// Topics
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;  // Adjacency list
    vector<int> state; // 0 = unvisited, 1 = visiting, 2 = visited

    bool hasCycle(int node, int parent) {
        state[node] = 1; // Mark node as visiting

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Ignore the edge that connects to parent
            if (state[neighbor] == 1) return true; // Cycle detected
            if (state[neighbor] == 0 && hasCycle(neighbor, node)) return true;
        }

        state[node] = 2; // Mark node as fully processed
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();  // Number of nodes
        adj.resize(n + 1);     // Resize adjacency list for 1-based index

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            // Reset state before checking for cycle
            state.assign(n + 1, 0);

            // Add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Check if adding this edge creates a cycle
            if (hasCycle(u, -1)) {
                return {u, v};  // This edge forms a cycle, return it
            }
        }
        return {};
    }
};
