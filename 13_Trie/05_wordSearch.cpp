#include<iostream>
#include<unordered_map>
#include <string>
using namespace std;

//this help to create a node of trie
class Node {
    public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie {
    Node*root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key) { //O(l)
        Node* temp = root;

        for(int i = 0; i < key.size();i++){
            if (temp->children.count(key[i])== 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++){
            if (temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }

    bool startsWith(string prefix){ //O(l)
    Node* temp = root;
    
    for (int i = 0; i < prefix.size(); i++){
        if (temp->children[prefix[i]]){
            temp = temp->children[prefix[i]];
        }else{
            return false;
        }
    }
    return true;
 }
 int countHelper(Node* root){
    int ans = 0;
    for(pair<char, Node*>child : root->children){
        ans += countHelper(child.second);
    }
    return ans + 1;
 }
 int countNodes(){
    return countHelper(root);
 }
};




int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for(int i = 0; i < words.size(); i++){
        trie.insert(words[i]);
    }
    cout << trie.startsWith("app");
    return 0;
}