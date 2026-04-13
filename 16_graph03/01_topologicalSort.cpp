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
    void topoSortHelper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        list<int> neighbour = l[src];
        for(int v: neighbour){
            if(!vis[v]){
                topoSortHelper(v, vis, s);
            }
        }
        s.push (src); 
    }

    void topoSort(){
        vector<bool>vis(V, false);
        stack<int> s;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSortHelper(i, vis, s);
            }
        }
        while(s.size() > 0){
            cout << s.top()<< " ";
            s.pop();
        }
        cout << endl;
    }
};

int main(){
    Graph g(6, false);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    
    g.topoSort();
    return 0;
}