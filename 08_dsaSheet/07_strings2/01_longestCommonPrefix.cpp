#include<iostream>
#include<string>
#include<vector>
using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if (i >= strs[j].size() || strs [j][i]!= ch){
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }

    int main(){
        vector<string>strs{"flower","flow","flight"};
        longestCommonPrefix(strs);
        return 0;
    }