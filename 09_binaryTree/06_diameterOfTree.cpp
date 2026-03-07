//number of nodes in the longest path between two leaf
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
int hieght(Node* root){
    if (root== NULL){
        return 0;
    }
    int leftHie = hieght(root->left);
    int rightHie = hieght(root->right);

    int currHie = max(leftHie, rightHie) + 1;
    return currHie;
}

int dia1(Node* root){
    // first we calculate the current dia and then we calculate the right dia and the answer id the resultant of max of the curr and max of left , rightdia
    if (root == NULL){
        return 0;
    }
    int currDia = hieght(root -> left) + hieght(root-> right) + 1; //current node
    int leftDia = dia1(root->left); // left subtree
    int rightDia = dia1(root->right); // right subtree

    return max(currDia, max(leftDia, rightDia));
}

pair <int, int> dia2(Node* root){
    if (root == NULL){
        return make_pair(0, 0);
    }
    //(diameter, hieght)
    pair<int, int> leftInfo = dia2(root->left);// LD,LH
    pair<int, int> rightInfo = dia2(root->right); // RD, RH

    int currDia = leftInfo.second + leftInfo.second + 1;
    int finalDia = max(currDia,max(leftInfo.first, rightInfo.first));
    int finalHt =  max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDia, finalHt);
}

int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    cout << "Diameter : " << dia2(root).first << endl;
    return 0;
}


