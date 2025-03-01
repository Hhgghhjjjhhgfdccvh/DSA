// Detecting a Cycle in an Undirected Graph Using BFS (Breadth-First Search)
// 🔍 Concept
// In an undirected graph, a cycle exists if:

// A node is visited again but is not its parent.
// ✅ Approach
// Use a queue (BFS traversal).
// Track visited nodes using a visited array.
// For each unvisited node, perform BFS:
// If a node is visited again but not from its parent, a cycle is detected.

//ALREADY VISITED AND NOT ALSO PARENT--------------------------------------------------->FOUND A CYCLE

bool detectCycleBFS(int start,vector<int>adj[],vector<bool>&visited){
    queue<pair<int,int>>q;

    q.push({start,-1});
    visited[start]=true;

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(int neibor:adj[node]){
            if(!visited[neibor]){
                visited[neibor]=true;
                q.push({neibor,node});
            }

            else  if (neibor !=parent){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int V, vector<int>adj[]){

    vector<bool>visited(v,fslse);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(detectCycleBFS(i,adj,visited))return true;
        }
    }
    return false
}