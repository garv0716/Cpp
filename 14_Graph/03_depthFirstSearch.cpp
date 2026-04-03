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
    //DFS -> keep going to 1st unvisited neighbour
    void dfsHelper(int u, vector<bool> &vis){ // O(v + e)
        vis[u] = true;
        cout << u << " ";

        list <int> neighbous = l[u];
        for(int v: neighbous){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(7, false);
        dfsHelper(0, vis);
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


    graph.dfs();
    return 0;
}

/*
========================================================
        DFS (DEPTH FIRST SEARCH) - INTERVIEW NOTES
========================================================

PROBLEM / GOAL
--------------
Traverse a graph by going as deep as possible before
backtracking.

Think:
"Explore completely, then move to next option"


--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

DFS = Depth First

• Go to first unvisited neighbor
• Keep going deeper
• When stuck → backtrack

Implementation:
• Recursion (most common)
• Stack (iterative)


--------------------------------------------------------
CODE PATTERN (IMPORTANT)
--------------------------------------------------------

void dfs(int node, vector<bool> &vis){
    vis[node] = true;

    for(auto neighbor : adj[node]){
        if(!vis[neighbor]){
            dfs(neighbor, vis);
        }
    }
}

👉 Always mark visited BEFORE recursive call


--------------------------------------------------------
TIME & SPACE
--------------------------------------------------------

Time: O(V + E)
Space: O(V)  (visited + recursion stack)


--------------------------------------------------------
INTERVIEW INTUITION
--------------------------------------------------------

Whenever you see:

• "Explore all paths"
• "Check connectivity"
• "Go deep / recursive structure"
• "Grid traversal"

👉 DFS is usually the first choice


--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

❌ Forgetting visited array → infinite loop  
❌ Marking visited AFTER recursion → TLE / cycles  
❌ Not handling disconnected graph  
❌ Stack overflow in deep recursion  


--------------------------------------------------------
FOLLOW-UP QUESTIONS
--------------------------------------------------------

1. DFS on DISCONNECTED GRAPH

👉 Run DFS from every unvisited node

for(int i = 0; i < V; i++){
    if(!vis[i]){
        dfs(i, vis);
    }
}


2. ITERATIVE DFS (using stack)

stack<int> st;
st.push(start);

while(!st.empty()){
    int node = st.top();
    st.pop();

    if(vis[node]) continue;

    vis[node] = true;

    for(auto neigh : adj[node]){
        if(!vis[neigh]){
            st.push(neigh);
        }
    }
}


3. CYCLE DETECTION

Undirected Graph:
👉 If visited neighbor ≠ parent → cycle

Directed Graph:
👉 Use recursion stack (visited + path array)


4. PATH EXISTENCE

👉 DFS can check if path exists between two nodes


5. TOPOLOGICAL SORT

👉 DFS + stack (post-order)


6. CONNECTED COMPONENTS

👉 Count how many times DFS is called


--------------------------------------------------------
DFS vs BFS (IMPORTANT DIFFERENCE)
--------------------------------------------------------

DFS:
• Goes deep
• Uses stack / recursion
• Good for path & structure problems

BFS:
• Level order
• Uses queue
• Best for shortest path (unweighted)


--------------------------------------------------------
GRID BASED DFS (VERY COMMON)
--------------------------------------------------------

Used in problems like:

• Number of Islands
• Flood Fill
• Surrounded Regions

Pattern:

dfs(i, j):
    check boundaries
    mark visited
    explore 4 directions


--------------------------------------------------------
OPTIMIZATION / ADVANCED
--------------------------------------------------------

• Tail recursion → convert to iterative
• Use bitset instead of vector<bool> for speed
• Avoid recursion for very deep graphs


--------------------------------------------------------
WHEN TO USE DFS IN INTERVIEW
--------------------------------------------------------

Choose DFS when:

✔ Need full traversal  
✔ Need to explore all possibilities  
✔ Backtracking involved  
✔ Graph depth matters  

Avoid DFS when:

❌ Need shortest path (use BFS)


--------------------------------------------------------
PRO TIP
--------------------------------------------------------

👉 "DFS = Explore → Backtrack → Explore"

If problem feels like:
"try all possibilities"

→ It's DFS or backtracking


========================================================
*/