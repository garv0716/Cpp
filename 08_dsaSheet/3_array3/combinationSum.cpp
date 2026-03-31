#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates,
                int target,
                int index,
                vector<int>& current,
                vector<vector<int>>& ans)
    {
        if(target == 0){
            ans.push_back(current);
            return;
        }

        if(index >= candidates.size() || target < 0)
            return;

        current.push_back(candidates[index]);
        helper(candidates, target - candidates[index], index, current, ans);
        current.pop_back();

        helper(candidates, target, index + 1, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        helper(candidates, target, 0, current, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    int n, target;
    cin >> n;

    vector<int> candidates(n);
    for(int i = 0; i < n; i++)
        cin >> candidates[i];

    cin >> target;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    for(auto &vec : result){
        cout << "[ ";
        for(int x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}