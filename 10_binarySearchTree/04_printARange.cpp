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
bool search(Node* root, int key){ // O(height); avg => O(logn)
    if (root == NULL){
        return false;
    }
    if (root->data == key){
        return true;
    }
    if (root->data > key){
        return search (root->left, key);
    }else{
        return search(root->right, key);
    }
}
Node* getInorderSuccessor(Node* root){
    // here there is no need to check the null value of the root because the call if inorder is proccessed in case 3 before that we already check for the null value
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

void printInRange (Node* root, int start, int end){
    if (root == NULL){
        return;
    }
    if (start <= root->data && root->data <= end){
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }
    else if (root->data < start){
        printInRange(root->right,start,end);
    }else{
        printInRange(root->left,start,end);
    }
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);
    inorder (root);
    cout<<endl;

    printInRange(root, 3, 7);

    inorder (root);
    cout<<endl;

    return 0;
}