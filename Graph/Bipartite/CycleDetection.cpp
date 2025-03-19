// 684. Redundant Connection
// Medium
// Topics
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 //SOLUTION❤❤❤🤣🤣😂😂😊😊❤🤣🤣😂😂😊

 //BASICALLY FINDING CYCLE AND REMOVING IT WILL HELP TO FIND ANSWER


 class Solution{

    public:
      bool hasCycle(int node,vector<vector<int>>&adj, vector<int>& state){
        if (state[node]==1) return true; 
        if (state[node]==2) return false;

        state[node]=1 //mark node as visiting

        for(int neighbor:adj[node]){
            if(hasCycle(neigbor,adj,state))
               return true;
        }

        state[node]=2;
        return false;
      }
 }