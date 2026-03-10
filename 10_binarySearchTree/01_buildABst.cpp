#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
     this->data = data;
     left= right= NULL;
    }
};

Node* insert(Node* root, int val){ // O(logn)

    //base case
    if (root == NULL){
        root = new Node(val);
        return root;
    }
    if(val < root->data){
       root->left =  insert(root->left, val); //this function will insert the value in leftsubtree and return the updated value of left subtree, so we assign that value to the root ka left.
    }
    else{
       root-> right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i = 0; i < n; i++){
       root =  insert(root, arr[i]); // recursive call
    }
    return root;
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);
    inorder(root);
    cout<<endl;
    buildBST(arr, 6);
}

