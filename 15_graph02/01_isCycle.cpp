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

        bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbours = l[src];

        for (int v : neighbours){
            if (!vis[v]){
                dirCycleHelper(v, vis, recPath);
                return true;
            } else if (recPath[v]){
                return true;
            }
        }

        recPath[src] = false;
        return false;
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
};

int main(){
    Graph g(4, false);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout << g.isCycleDirected()<< endl;
}

