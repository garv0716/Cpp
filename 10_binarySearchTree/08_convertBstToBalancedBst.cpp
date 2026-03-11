#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* buildfromSortedVec(vector<int>nodes, int st, int end){

    if (st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;
    //root
    Node* curr = new Node (nodes[mid]);
    //left subtree
    curr->left = buildfromSortedVec(nodes, st, mid-1); // return left node pointer
    curr->right = buildfromSortedVec(nodes, mid+1, end);
    return curr;
}

void getInorder(Node* root, vector<int> &nodes){
    if (root == NULL){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);

}
Node* balancedBST(Node* root){
    //get inorder seq
    vector<int>nodes;
    getInorder(root, nodes);

    //Building BST
    return buildfromSortedVec(nodes,0, nodes.size()-1 );
   

}

void preorder(Node* root){
    if (root == NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
}

int main(){
   Node* root = new Node(6);
   root->left = new Node(5);
   root->left->left = new Node(4);
   root->left->left->left = new Node(3);

   root->right = new Node(7);
   root->right-> right= new Node(8);
   root->right ->right ->right = new Node(9);

   root = balancedBST(root);
   preorder(root);
   cout<<endl;
 
    return 0;
}
