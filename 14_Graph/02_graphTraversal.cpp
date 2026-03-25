#include<iostream>
#include<vector>
#include<list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int>*l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v) { //u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }  
    void print(){
        for (int u = 0; u < V; u++){
            list<int> neighbors = l[u];
            cout << u << ":" ;
            for(int v : neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
    }
    void bfs(){ // O(V + E)
        queue<int>q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout << u << " ";

            list <int> neighbours = l[u];
            for(int v: neighbours){
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
         }
         cout << endl;
    }
};

int main(){
    Graph graph(7);
   
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    graph.bfs();
    return 0;
}


/*
========================================================
                BFS (BREADTH FIRST SEARCH)
========================================================

PROBLEM / GOAL
--------------
Traverse all nodes of a graph level by level starting
from a source node (here node 0).

Used for:
• Shortest path in unweighted graph
• Level order traversal
• Checking connectivity


--------------------------------------------------------
GRAPH REPRESENTATION
--------------------------------------------------------

Using **Adjacency List**

l[u] → stores all neighbors of node u

Example

0 → 1,2  
1 → 0,3  
2 → 0,4  

Efficient for sparse graphs.


--------------------------------------------------------
CORE IDEA OF BFS
--------------------------------------------------------

BFS explores nodes **level by level**.

Process:

1. Start from source node
2. Visit all its neighbors
3. Then visit neighbors of neighbors

👉 Uses **Queue (FIFO)**


--------------------------------------------------------
ALGORITHM
--------------------------------------------------------

1. Create queue

2. Create visited array

3. Push starting node (0)

4. Mark it visited

5. While queue not empty

   • take front node (u)  
   • print it  
   • for all neighbors of u  

       if not visited  
           mark visited  
           push into queue  


--------------------------------------------------------
DRY RUN (IMPORTANT)
--------------------------------------------------------

Graph

0 → 1,2  
1 → 3  
2 → 4  
3 → 4,5  
4 → 5  
5 → 6  

Start from 0


Step-by-step

Queue = [0]

Visit 0 → push 1,2  
Queue = [1,2]

Visit 1 → push 3  
Queue = [2,3]

Visit 2 → push 4  
Queue = [3,4]

Visit 3 → push 5  
Queue = [4,5]

Visit 4 → (5 already visited)  
Queue = [5]

Visit 5 → push 6  
Queue = [6]

Visit 6 → done


Output

0 1 2 3 4 5 6


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

O(V + E)

V → vertices  
E → edges  

Each node and edge is visited once.


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(V)

for visited array + queue.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• BFS uses **Queue (FIFO)**  
• Always mark visited before pushing  
• Prevents infinite loops  
• Works for shortest path in unweighted graph  
• Traverses graph level by level  

========================================================
*/