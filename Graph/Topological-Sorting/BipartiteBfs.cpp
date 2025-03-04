 #include <iostream>
 #include <vector>
 #include <queuue>
 
 using namespace std;

 bool isBipartite(vector<vector<int>>& adj,int n){
    vector<int> color(n,-1);
    queue<int>q;


    for(int start=0;start<n;start++){
        if(color[start]==-1){
            q.push(start);
            color[start]=0;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int neighbour:adj[node]){
                  if(color[neighbor]==-1){//if uncolored, assign opposite color
                    color[neighbor]=1-color[node];
                    q.push(neighbor);
                  }else if (color[neighbor]==color[node]){
                    return false;
                  }
                }

            }
        }
    }

    return true;
 }