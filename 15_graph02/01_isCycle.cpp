#include<iostream>
#include<list>
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

    bool dirCycleHelper(int sec, )


    bool isCycleDirected(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++){
            if (vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;

    }
     
};

int main(){

}