// 743. Network Delay Time (✅ Must-Do)

// Type: Standard Dijkstra’s Algorithm for finding shortest paths.
// Concepts: Graph representation, Priority Queue, Relaxation.

//my code in cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm> // For max_element
using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    vector<int> dij(int n, int k, vector<vector<pii>> &adj) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq; // Min heap

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto &nei : adj[node]) {
                int adjNode = nei.first;
                int weight = nei.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n);

        // Build the adjacency list (1-indexed nodes in input)
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }

        vector<int> dist = dij(n, k - 1, adj);

        // Find the maximum time to reach all nodes
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

