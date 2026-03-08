// we solve this question with 2 apporaches 
//. - in first apporach the TC = O(n); SC = O(n)
//. - in second apporach the TC = O(n); SC = O(1)
// Both are important for interview purposes

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

// optimized LCA version with constant space complexity 
Node* LCA2(Node* root, int n1, int n2){

    //base case 
    if (root == NULL){
        return NULL;
    }

    if (root->data == n1 || root->data == n2){
        return root;
    }
    Node* leftLca= LCA2(root->left, n1, n2);
    Node* rightLca= LCA2(root->right, n1, n2);

    // case 4: when both are valid
    if (leftLca != NULL && rightLca != NULL){
        return root;
    }

    // other three cases, agar leftLca ki value NULL hai toh rightLca ko return krr do wrrna leftLca ko return krr do.
    return leftLca == NULL ? rightLca : leftLca;
}



int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    int n1= 4, n2= 5;
    cout << "lca = " << LCA(root, n1, n2) << endl;
    return 0;
}
