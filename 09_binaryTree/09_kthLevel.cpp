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

void kthHelper(Node* root, int K, int currLevel){
    if (root == NULL){
        return;
    }
    if (currLevel == K){
        cout << root->data << " ";
        return;
    }
    kthHelper(root->left, K , currLevel+1); //left
    kthHelper(root->right, K , currLevel+1); //left
}

void kthLevel(Node* root, int k){
    kthHelper(root, k , 1); //generally in coding or interview question there is only two paramentes are given in function so we can create an helper function so that we can use an extra parameters in it 
    cout << endl;
}

int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    kthLevel(root, 3);
    return 0;
}


// TC : O(n), because in worst case we have to travell the whole tree.