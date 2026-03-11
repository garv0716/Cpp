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

Node* buildBSTfromSortedArr(int arr[], int st, int end){

    if (st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;
    //root
    Node* curr = new Node (arr[mid]);
    //left subtree
    curr->left = buildBSTfromSortedArr(arr, st, mid-1); // return left node pointer
    curr->right = buildBSTfromSortedArr(arr, mid+1, end);
    return curr;
}
void preorder(Node* root){
    if (root == NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[7] = {3,4,5,6,7,8,9};
    Node* root = buildBSTfromSortedArr(arr,0,6);

    // for check we print the preorder sequence of the tree
    preorder(root);

    return 0;
}