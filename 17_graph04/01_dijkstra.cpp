#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Edge{
    public:
        int v;
        int wt;

        Edge(int v, int wt){
            this ->v = v;
            this -> wt = wt;
        }
};
void dijkstra(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;//min heap
    //pair(dist[v], v);
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges){
            if(dist[e.v]> dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v] , e.v));
            }
        }
    }
    for(int d : dist){
        cout << d << " ";
    }
    cout << endl;
}
int main(){
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));

    dijkstra(0, graph, V);

    return 0;


}

/*
========================================================
        DIJKSTRA'S ALGORITHM - INTERVIEW NOTES
========================================================

PROBLEM / GOAL
--------------
Find the **shortest distance from a source node to all
other nodes** in a weighted graph.

Condition:
👉 All edge weights must be NON-NEGATIVE


--------------------------------------------------------
CORE IDEA (VERY IMPORTANT)
--------------------------------------------------------

Dijkstra is a **Greedy Algorithm**.

At every step:
👉 Pick the node with the **minimum distance so far**
👉 Relax its edges

This ensures shortest path is built incrementally.


--------------------------------------------------------
EDGE RELAXATION (HEART OF DIJKSTRA)
--------------------------------------------------------

For every edge (u → v, wt):

if (dist[v] > dist[u] + wt)
{
    dist[v] = dist[u] + wt;
}

Meaning:
👉 Found a shorter path → update it


--------------------------------------------------------
DATA STRUCTURES USED
--------------------------------------------------------

1. Distance Array

vector<int> dist(V, INT_MAX)

dist[i] → shortest distance from source to i


2. Min Heap (Priority Queue)

priority_queue<pair<int,int>, ..., greater<>> pq

Stores:
(dist, node)

👉 Always processes node with minimum distance first


--------------------------------------------------------
ALGORITHM FLOW
--------------------------------------------------------

1. Initialize

dist[src] = 0  
push (0, src) into pq


2. While pq not empty

   • extract node with smallest distance (u)

   • for each neighbor (v, wt)

       if relaxation possible
           update dist[v]
           push (dist[v], v) into pq


3. Final dist[] contains shortest paths


--------------------------------------------------------
DRY RUN (INTUITION)
--------------------------------------------------------

Think like:

👉 Expanding a circle from source

Closest nodes get finalized first.

Example flow:

0 → relax neighbors → update  
next closest → relax → update  
...

Distances always grow optimally.


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

Using Min Heap:

O((V + E) log V)

• Each edge processed once
• Heap operations cost log V


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(V + E)


--------------------------------------------------------
IMPORTANT INTERVIEW POINTS
--------------------------------------------------------

1. WHY MIN HEAP?

👉 Always need the node with smallest distance  
👉 Greedy choice → optimal solution


2. WHY NO VISITED ARRAY?

👉 Can be used, but not mandatory  
👉 Multiple entries of same node may exist in pq  
👉 Only smallest one matters


3. WHEN DIJKSTRA FAILS?

❌ Negative edge weights

Example:

A → B = 5  
A → C = 2  
C → B = -10  

Dijkstra gives wrong answer

👉 Use Bellman-Ford instead


4. BFS vs DIJKSTRA

BFS:
• Unweighted graph
• All edges = 1

Dijkstra:
• Weighted graph
• Different edge costs


--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

❌ Forgetting min heap (using default max heap)  
❌ Not handling INT_MAX overflow  
❌ Using Dijkstra with negative weights  
❌ Not pushing updated distance back into pq  


--------------------------------------------------------
FOLLOW-UP QUESTIONS
--------------------------------------------------------

1. PRINT SHORTEST PATH (not just distance)

👉 Maintain parent array

parent[v] = u


2. DIJKSTRA USING SET

set<pair<int,int>> instead of pq  
Helps in decrease-key operation


3. MULTI-SOURCE DIJKSTRA

👉 Push multiple sources initially with distance 0


4. GRID BASED SHORTEST PATH

👉 Treat grid as graph  
👉 Use Dijkstra when weights vary  


5. OPTIMIZATION

👉 Skip outdated entries

if(currDist > dist[u]) continue;


6. K SHORTEST PATHS

👉 Extension using modified heap logic


--------------------------------------------------------
ADVANCED INSIGHT
--------------------------------------------------------

Dijkstra is basically:

👉 BFS + Priority Queue

Instead of FIFO (queue),
we use Min Heap to prioritize smaller distances.


--------------------------------------------------------
WHEN TO USE DIJKSTRA
--------------------------------------------------------

✔ Weighted graph  
✔ No negative weights  
✔ Need shortest path  
✔ Greedy choice works  


--------------------------------------------------------
PRO TIP
--------------------------------------------------------

👉 "Relax edges only when you find a better path"

👉 "Min heap ensures correct order of processing"


========================================================
*/