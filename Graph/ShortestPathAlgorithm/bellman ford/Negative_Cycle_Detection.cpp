// Bellman-Ford Algorithm for Detecting Negative Weight Cycles
// The Bellman-Ford algorithm can detect negative weight cycles in a directed graph by performing one extra iteration beyond the standard 
// 𝑉
// −
// 1
// V−1 relaxations.

// How It Works?
// Relax all edges 
// 𝑉
// −
// 1
// V−1 times
// Each relaxation step ensures that the shortest path to each node is updated.
// Perform one more relaxation (V-th iteration)
// If any edge can still be relaxed (i.e., a shorter path is found), then a negative weight cycle exists.

