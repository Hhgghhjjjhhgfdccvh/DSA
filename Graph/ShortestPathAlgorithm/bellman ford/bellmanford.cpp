class solution{
    public:
    void bellmanFord(int v, int src, vector<vector<int>>& edges){

        vector<int>dist(V,INT_MAX);
        dist[src]=0;

        for(int i=0;i<V-1;i++){
            for(auto edge :edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];

                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }

        //step 3 check for negative weight cycles
        for(auto edge :edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                cout<<"Negative weight cycle detected!\n";
                return;
            }
        }

        //now dist array contains distance between source and all edges
    }
}