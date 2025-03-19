// How to find Shortest Paths from Source to all Vertices using Dijkstra’s Algorithm????????

#include <iostream>
#include <bits/stdc++.h>


typedef pair<int,int>pii;
void dijkstra(int V, vector<vector<pii>>&adj,int src){
    vector<int> dist(V,INT_MAX);//creating a distance array
    priority_queue<pii,vector<pii>,greater<pii>>pq; //minheap priority queue
    
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int currDist=pq.top().first;
        int node=pq.top().second;
        pq.pop();//basically we need our history to check for past so we took out all values for it

        //skip the path if not optimal anymore
        if(currDist>dist[node]) continue;

        for(auto & neighbour : adj[node])//see hoe neibour is takrn out
        int adjNode=neigbour.first;
        int weight=neibour.second;
        if(dist[node]+weight<dist[adjNode]){
            dist[adjNode]=dist[node]+weight;
            pq.push({dist[adjNode],adjNode});

        }
    }
    //your answer will be distant array

}
