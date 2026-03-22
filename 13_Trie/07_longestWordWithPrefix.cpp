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
    string longestHelper(Node* root,string &ans, string temp){
        for (pair<char, Node*> child : root->children){
            if (child.second->endOfWord){
                temp += child.first;

            if ((temp.size() == ans.size() && temp < ans )|| (temp.size() > ans.size())){
                ans = temp;
            }

            longestHelper(child.second, ans, temp);
            temp = temp.substr(0, temp.size()-1);
            }
        }
    }
    // we need to create a helper function because root is the private member
    string longestStringWithEow(){
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string>dict){
    Trie trie;

    for (int i = 0; i < dict.size(); i++){
        trie.insert(dict[i]);
    }
    return trie.longestStringWithEow();
}
int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    cout << longestWord(words)<< endl;
    return 0;
}