// 1631. Path With Minimum Effort
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
public:
  typedef pair<int,int>pii;

  int minimumEffortPath(vector<vector<int>>& heights){
    int rows=heights.size();
    int cols=heights[0].size();

    vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
    priority_queue<pii,vector<pii>,greater<pii>>pq;//min heap

    //start from top left with 0 effort
    pq.push({0,{0,0}});
    dist[0][0]=0;
    //Direction for moving up, down, left, right
    vector<int> dr={-1,1,0,0};
    vector<int> dc={0,0,-1,1};

    while(!pq.empty()){
        auto [currEffort,cell]=pq.top();

        int row=cell.first;
        int col=cell.second;
        pq.pop();
        //if we reach the bottom right cell
        if(row==rows-1 && col==cols-1){
            return currEffort;
        }
        //explore all four possible dirrctions
        for(int i=0;i<4;i++){
            int newRow=row+dr[i];
            int newCol=col+dc[i];
            //Boundary Check
            if(newRow >=0 && newRow<rows && newCol >=0 && newCol<cols){
                int newEffort=max(currEffoort,abs(heights[row][col]-heights[newRow][newCol]))

                //if this path has less effort than previously recored
                if(newEffort <dist[newRow][newCol]){
                    dist[newRow][newCol]=newEffort;
                    pq.push({newEffort,{newRow,newCol}});
                }
            }
          
        }

    }
    return 0;
  }

  //time complexity
//   Time Complexity Analysis of the Solution
//   The solution uses Dijkstra’s Algorithm with a Min-Heap (Priority Queue). Let's break down the time complexity step by step to understand it fully.
  
//   🔹 Step 1: Initialization
//   Creating the dist array of size m × n (where m = rows, n = columns)
//   Time Complexity: O(m × n)
//   🔹 Step 2: Priority Queue Operations
//   In Dijkstra’s algorithm:
  
//   Each cell in the grid represents a node. Thus, there are m × n nodes in total.
//   Each node can have up to 4 neighbors (up, down, left, right).
//   ➡️ Total Possible Edges: 4 × m × n (in the worst case)
  
//   The priority queue processes each node once.
//   Every time a node is processed, we perform:
//   pop() operation → O(log(m × n))
//   Up to 4 push() operations → O(log(m × n)) each
//   🔹 Why log(m × n) for Priority Queue Operations?
//   The maximum number of entries in the priority queue can be m × n in the worst case (when every cell is added to the queue). Each insertion and removal takes logarithmic time.
  
//   🔹 Step 3: Overall Complexity Calculation
//   Initialization: O(m × n)
//   Priority Queue Operations: Each node may be inserted multiple times (at most once per edge). Since there are 4 × m × n possible edges, the total priority queue operations will be:
//   𝑂
//   (
//   (
//   𝑚
//   ×
//   𝑛
//   )
//   log
//   ⁡
//   (
//   𝑚
//   ×
//   𝑛
//   )
//   )
//   O((m×n)log(m×n))
//   🔹 Final Complexity
//   Time Complexity: O(m × n log(m × n))
//   Space Complexity: O(m × n) (for the distance array and the priority queue)
  