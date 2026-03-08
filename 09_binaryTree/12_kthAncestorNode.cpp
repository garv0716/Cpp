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

// out int return type function is return the distance between the current node and the root node, and with the help of that value we find the valid ancestor
int kthAncestor(Node* root, int node, int k){
    //Base case
    if (root == NULL){
        return -1;
    }
    //Matching Condition
    if (root->data == node){
        return 0;
    }

    int leftDist = kthAncestor(root->left, node, k);
    int rightDist = kthAncestor(root->right, node, k);

    //When value not exists
    if (leftDist == -1 && rightDist == -1){
        return -1;
    }
    //if we find value
    //agar left dis -1 hai, tab toh valid value right dis ki hogi nhi toh leftDist ki hogi
    int validVal = leftDist == -1 ? rightDist : leftDist;

    // now we check if our valid valure is equal to k or not 
    if (validVal + 1 == k){
        cout << "Kth Ancestor : " << root->data << endl;
    }

    return validVal + 1;

}



int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    int node = 4, k = 2;
    kthAncestor(root, node, k);

    return 0;
}
