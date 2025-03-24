// 1129. Shortest Path with Alternating Colors
//code in cpp

vector<int> shortestAlternatingPath(int n, vector<vector<int>>&redEdges, vector<vector<int>>&blueEdges){



    vector<vector<int>> redAdj(n),blueAdj(n);

    //create adjanccency lists
    for(auto& edge :redEdges) redAdj[edge[0]].push_back(edge[1]);
    for(auto & edge:blueEdges) blueAdj[edge[0]].push_back(edge[1]);


    //BFS QUEUE(node,color,distance)
    queue<tuple<int ,int,int>>qu;
    vector<vector<int>> dist(n,vector<int>(2,INT_MAX)); //dist[node][0]=red,dist[node][1]=blue

    //start BFS from node 0 using both colors
    qu.push({0,0,0});//distsnce of 0 from 0 via red is 0
    qu.push({0,1,0});//distance of 0 from 0 via blue is 0

    dist[0][0]=dist[0][1]=0;

    while(!qu.empty()){
        auto [node,color,distance]=qu.front();
        qu.pop();

        //Select next edges based on current color
        vector<int>& nextEdges=(color==0)?blueAdj[node]:redAdj[node];
        int nextColor=1-color;
        for(int neighbor:nextEdges)
{
    if(dist[neighbor][nextColor]==INT_MAX){
        dist[neighbor][nextColor]distance+1;
        q.push({neighbor,nextColor,distance+1});
    }
}
    }


 //prepare answer
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        ans[i]=min(dist[i][0],dist[i][1]);
          if(ans[i]==INT_MAX) ans[i]=-1// if unreachable
    }

    return ans;

}

