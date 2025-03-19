



// Here’s a simplified version of Kosaraju’s Algorithm:

// DFS on Original Graph: Record finish times.
// Transpose the Graph: Reverse all edges.
// DFS on Transposed Graph: Process nodes in order of decreasing finish times to find SCCs.



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, adj, visited, st);
            }
        }
        st.push(node); // Push node after visiting all its neighbors
    }

    void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& visited, vector<int>& scc) {
        visited[node] = true;
        scc.push_back(node);
        for (int neighbor : revAdj[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, revAdj, visited, scc);
            }
        }
    }

    vector<vector<int>> findSCCs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), revAdj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);   // Original graph
            revAdj[edge[1]].push_back(edge[0]); // Transposed graph 
        }

        // Step 1: DFS on original graph to get finish order
        stack<int> st;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }

        // Step 2: DFS on transposed graph
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                vector<int> scc;
                dfs2(node, revAdj, visited, scc);
                sccs.push_back(scc);
            }
        }

        return sccs;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    int n = 5;
    vector<vector<int>> sccs = sol.findSCCs(n, edges);

    cout << "Strongly Connected Components:" << endl;
    for (auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
