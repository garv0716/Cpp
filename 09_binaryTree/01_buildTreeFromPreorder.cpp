#include<iostream>
#include<vector>
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

// Preorder :  root-> left-> right
void preOrder (Node* root){

    if (root == NULL){
        return;
    }
    //root
    cout << root->data << endl;
    //left
    preOrder(root->left);
    //right
    preOrder(root->right);

}
//Inorder : left -> root -> right
void inOrder(Node* root){
    if (root == NULL){
        return;
    }
    //left
    inOrder(root-> left);
    //root
    cout << root->data << " ";
    //right
    inOrder(root-> right);
}

//Postorder : left -> right -> root
void postOrder(Node* root){
    //base case
    if (root == NULL){
        return;
    }
    //left
    postOrder(root-> left);
    //right
    postOrder(root-> right);
    //root
    cout<< root->data << " ";
}


int main(){

    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // cout<< "root =" << root -> data << endl;  

    // preOrder(root); // Time comeplexity is O(n), where n is the number of node. its not exponential TC
    // cout << endl;
    inOrder(root); // TC = O(n)
    return 0;
}