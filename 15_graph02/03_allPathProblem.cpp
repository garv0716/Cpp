#include<iostream>
#include<list>
#include<vector>
#include<string>
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

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout << path << dest;
            return;
        }
        vis[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];
        for(int v : neighbours){
            if (!vis[v]){
                pathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size() - 1);
        vis[src] = false;


    }
    void printAllPath(int src, int dest){
        vector<bool>vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main(){
    Graph g(6, false);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.printAllPath(5, 1);


}