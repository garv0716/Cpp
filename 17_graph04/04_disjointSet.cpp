#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        this -> n = n;
        
        for (int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(0); 
        }
    }

    int find(int x){
        if (parent[x] = x){
            return x;
        }
         return parent[x] = find(parent[x]); // path compression
    }

    void unionByRank(int a, int b){
         int parA = find(a);
         int parB = find(b);

         if (rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++; 

         }else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
         }else{
            parent[parA] = parB;
         }
    }
    void getInfo(){
        for(int i=0; i<n; i++){
            cout<< i << ":" << parent[i] << "," << rank[i];
        }
    }

};


int main(){
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout<< dj.find(2) << endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout<< dj.find(2) << endl;
    dj.unionByRank(0,4);

    dj.getInfo();  

}