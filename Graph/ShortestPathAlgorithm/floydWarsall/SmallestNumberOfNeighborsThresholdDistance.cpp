// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
//code
class Solution {
public:
    void floydWarshall(int V, vector<vector<int>>& dist) {
        for (int k = 0; k < V; k++) { // Intermediate vertex
            for (int i = 0; i < V; i++) { // Source vertex
                for (int j = 0; j < V; j++) { // Destination vertex
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Creating the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize the diagonal (distance to itself is 0)
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Fill in the direct edges
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w; // Since the graph is undirected
        }

        // Run Floyd-Warshall to compute shortest paths
        floydWarshall(n, dist);

        int minCity = -1, minCount = INT_MAX;

        // Find the city with the minimum reachable cities within the threshold
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count < minCount || (count == minCount && i > minCity)) {
                minCount = count;
                minCity = i;
            }
        }

        return minCity;
    }
};
