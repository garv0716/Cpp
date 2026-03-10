/*
Cases for a node
 - no child(leaf node)
   ->simply delete that root, then return null
 - 1 child
   ->return the address of valid child, this will automaatically ignore that node
 - 2 child
   ->replace val with inorder successor. means the data or node just after that node
   ->delete inorder successor
   ->the inorder successor will always have either 0 or 1 child.basically it does not have two childern

   => In bst the left-most node in right subtree of a node is "inorrder successor" , leftmost node mean there is no left most child, right child is there 
*/
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

Node* delNode(Node* root, int val){
    if (root == NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = delNode(root->left, val);
    }else if (val > root->data){
        root->right = delNode(root->right, val);
    } else {
        //root == val
        //case 1 -> 0 chiildren node
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2-> 1 Child case
        if (root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }
        //case 3-> 2 child
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);

    }
    return root;
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);
    inorder (root);
    cout<<endl;

    delNode(root,4);

    inorder (root);
    cout<<endl;

    return 0;
}


