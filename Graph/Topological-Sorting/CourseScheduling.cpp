// The problem presents a scenario where you have n courses numbered from 1 to n.
// You are also given a list of pairs, relations, representing the prerequisite relationships between the courses. 
//Each pair [prevCourse, nextCourse] indicates that prevCourse must be completed before nextCourse can be taken.

// The goal is to determine the minimum number of semesters required to complete all n courses, given that you can take any number
// of courses in a single semester, but you must have completed their prerequisites in the previous semester.
// If it's not possible to complete all courses due to a circular dependency or any other reason, the result should be -1.

// Intuition
// To solve this problem efficiently, we use a graph-based approach known as Topological Sorting, which is usually applied to scheduling tasks or finding a valid order in which to perform tasks with dependencies.

// Here's a step-by-step breakdown of the intuition behind the solution:

// We consider each course as a node in a directed graph where an edge from node prevCourse to node nextCourse indicates that prevCourse is a prerequisite for nextCourse.

// We construct an in-degree list to track the number of prerequisite courses for each course. A course with an in-degree of 0 means it has no prerequisite and can be taken immediately.

// We then use a queue to keep track of all courses that have no prerequisites (in-degree of 0). This set represents the courses we can take in the current semester.

// For each semester, we dequeue all available courses (i.e., those with no prerequisites remaining) and decrease the in-degree of their corresponding next courses by 1, representing that we have taken one of their prerequisites.

// If the in-degree of these next courses drops to 0, it means they have no other prerequisites left, so we add them to the queue to be available for the next semester.

// We continue this process, semester by semester, keeping a counter to track the number of semesters necessary until there are no courses left to take.

// If at the end of this process, there are still courses left (i.e., n is not zero), it implies that there is a cycle or unsatisfiable dependency, and we return -1. Otherwise, we return the counter, which now holds the minimum number of semesters needed to take all courses.


int minimumSem(int n,vector<vector<int>>&relations){
    vector<vector<int>> graph(N);

    //indegree array to keep track of the number of prerequisite
    vector<int> inDegree(n);

    //graph representation where each node points to its successors
    vector<vector<int>> graph(N);
    //building the graph and filling indegree array

    for(auto & relations :relation){
        int prev=relation[0]-1;
        int next=relation[1]-1;

        graph[prev].push_back(next);
        intDegree[next]++;
    }

    //queue to perform topological sorting
      queue<int>queue;

      for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            queue.push(i);
        }
      }

      int semesters=0;
      //perform topological sorting using BFS
      while(!queue.empty()){
        semester++;
        //process all nodes in current level of the queue
        for(int levelSize=queue.size();levelSize>0;--levelSize){
            int course=queue.front();
            queue.pop();
            --n;
            //check all nexgt course the current course points to
            for(int next=graph[course]){
                if(--inDegree[next]==0)queue.push(next);//decrement the in degree and if it drops to 0 add it to the queue


            }
        }

        return n==0 ? semesters :-1
      }



}

