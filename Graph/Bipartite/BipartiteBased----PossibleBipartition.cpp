// 886. Possible Bipartition
// Medium
// Topics
// Companies
// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

class Solution {
    bool isBipartite(int n, vector<vector<int>>& adj) {
        vector<int> color(n, -1);
        queue<int> q;

        for (int start = 0; start < n; start++) {
            if (color[start] == -1) { // Unvisited node
                q.push(start);
                color[start] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbour : adj[node]) {
                        if (color[neighbour] == -1) {
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        } else if (color[neighbour] == color[node]) {
                            return false; // Conflict
                        }
                    }
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0] - 1; // Convert to 0-based indexing
            int v = dislikes[i][1] - 1; // Convert to 0-based indexing
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return isBipartite(n, adj);
    }
};

