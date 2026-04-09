#include<iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> *l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->isUndir = isUndir;
    }
    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        if (isUndir){
            l[v].push_back(make_pair(u, wt));
        }
    }
};