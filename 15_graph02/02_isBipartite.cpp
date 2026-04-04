#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndirected;

public:
    Graph(int V, bool isUndirected = true){
        this->V = V;
        l = new list<int>[V];
        this -> isUndirected = isUndirected;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
          if (isUndirected){ // false
            l[v].push_back(u);
          }
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbours = l[src];

        for (int v : neighbours){
            if (!vis[v]){
                if (dirCycleHelper(v, vis, recPath)){
                    return true;
                }
            } else if (recPath[v]){
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    void print(){
        for (int u = 0; u < V; u++){
            list<int> &neighbors = l[u];
            cout << u << ":" ;
            for(int v : neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
    }


    bool isCycleDirected(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;

    }

    // if there is dsconnected component in the graph then we made this function as a helper function and call it in a loop for all the vertices
    bool isBipartite(){
        queue<int> q;
        // vector<bool> vis(V, false);
        vector<int>color(V, -1);
        // vis[0] = 0;

        q.push(0);
        // vis[0] = true;
        color[0] = 0; //blue

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];

            for(int v: neighbours){
                if(color[v] == -1){
                    // vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }else if(color[v] == color[curr]){
                        return false;
                    }
            
            }
        }
        return true;
    }
};

int main(){ 
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    cout << g.isBipartite()<< endl;

}