#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> cmp(n, 0);

        for (int i = 1; i < n; i++) {
            cmp[i] = cmp[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> res;

        for (const auto &q : queries) {
            res.push_back(cmp[q[0]] == cmp[q[1]]);
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxDiff;
    cin >> maxDiff;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<bool> ans = obj.pathExistenceQueries(n, nums, maxDiff, queries);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << '\n';
    }

    return 0;
}