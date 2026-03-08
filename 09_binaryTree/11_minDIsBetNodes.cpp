/*
Approach:

-first we find the dis 1 = LCA to n1
-first we find the dis 2 = LCA to n2
-return dis 1 + dis 2
*/
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

int idx = -1;
Node* buildTree(vector<int>nodes){
    idx ++;
    if (nodes[idx]== -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode ->left = buildTree(nodes); // left subtree
    currNode ->right = buildTree(nodes); // right subtree

    return currNode;

}

bool rootToNodePath(Node* root, int n, vector<int> &path){ // O(n)
    if (root == NULL){
        return false;
    }
    path.push_back(root->data);
    if (root->data == n){
        return true;
    }
    int isLeft= rootToNodePath(root->left,n, path);
    int isRight= rootToNodePath(root->right,n, path);

    if (isLeft || isRight){
        return true;
    }
    path.pop_back(); 
    return false;

}

int LCA(Node* root, int n1, int n2){
    // first step
    vector<int>path1;
    vector<int>path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for (int i = 0 , j = 0; i < path1.size() && j < path2.size(); i++, j++){
    if (path1[i]!= path2[i]){
        return lca;
    }
    lca = path1[i];
    }
    return lca;
}


int dist(Node* root, int n){
    if (root == NULL){
        return -1;
    }
    if (root->data == n){
        return 0;
    }
    int leftDis = dist(root->left, n);
    if(leftDis != -1){
        return leftDis + 1;
    }
    int rightDis= dist(root->right, n);
      if(leftDis != -1){
      return leftDis + 1;
    }
    return -1;
}

int minDis(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);
 
    return dist1 + dist2;

}

int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
  
    return 0;
}