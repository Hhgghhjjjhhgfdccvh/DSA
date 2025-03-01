class Solution {
    public:
        bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state) {
            if (state[node] == 1) return true;  // Cycle detected
            if (state[node] == 2) return false; // Already processed
    
            state[node] = 1; // Mark node as visiting
    
            for (int neighbor : adj[node]) {
                if (hasCycle(neighbor, adj, state))
                    return true;
            }
    
            state[node] = 2; // Mark node as fully processed
            return false;
        }
    
        bool canFinish(int num, vector<vector<int>>& prereq) {
            vector<vector<int>> adj(num);
            vector<int> state(num, 0); // All nodes are unvisited initially
    
            // Build adjacency list
            for (auto edge : prereq) {
                adj[edge[1]].push_back(edge[0]);
            }
    
            // Check each node for a cycle
            for (int i = 0; i < num; i++) {
                if (state[i] == 0) { // Only unvisited nodes
                    if (hasCycle(i, adj, state))
                        return false; // Cycle found
                }
            }
    
            return true; // No cycle found
        }
    };
    