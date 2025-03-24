// The Floyd-Warshall algorithm is a dynamic programming approach used to find the shortest paths between all pairs of vertices in a weighted graph (both directed and undirected).

// Key Features:
// Works with negative edge weights but not with negative cycles.

// Uses a 3D DP approach to iteratively update shortest paths.

// The final result is a distance matrix where dist[i][j] represents the shortest distance from vertex i to vertex j.

// Time Complexity: 
// 𝑂
// (
// 𝑉
// 3
// )
// O(V 
// 3
//  ), where 
// 𝑉
// V is the number of vertices.

// Algorithm Explanation
// Initialization:

// If there is an edge between i and j, set dist[i][j] = weight(i, j).

// If i == j, set dist[i][i] = 0.

// If there is no edge between i and j, set dist[i][j] = ∞.

// Iterate Over Intermediate Nodes:

// Consider each node k as an intermediate node.

// Update the shortest path between every pair (i, j) using the formula:

// 𝑑
// 𝑖
// 𝑠
// 𝑡
// [
// 𝑖
// ]
// [
// 𝑗
// ]
// =
// min
// ⁡
// (
// 𝑑
// 𝑖
// 𝑠
// 𝑡
// [
// 𝑖
// ]
// [
// 𝑗
// ]
// ,
// 𝑑
// 𝑖
// 𝑠
// 𝑡
// [
// 𝑖
// ]
// [
// 𝑘
// ]
// +
// 𝑑
// 𝑖
// 𝑠
// 𝑡
// [
// 𝑘
// ]
// [
// 𝑗
// ]
// )
// dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
// This checks if a path through k is shorter than the current known path.

// Final Distance Matrix:

// After processing all vertices as intermediate nodes, dist[i][j] contains the shortest path between i and j.

// CODE IN CPP

void floydWarshall(vector<vector<int>>& dist, int V){

    for(int k=0;k<V;k++){//intermediate vertex
        for(int i=0;i<V;i++){//Source vertex
            for(int j=0;j<V;j++){//destination vertex
                if(dist[i][k]!=INF && dist[k][J]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

                }

            }
        }

    }
}
//now the dist matric is minimum distance matrix requited .

//Talking about Time Complexity and Space Complexity 
//Time Complexity is V*v*v
//Space complexity is V*V