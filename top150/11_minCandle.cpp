#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candlesIndex;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|')
                candlesIndex.push_back(i);
        }

        vector<int> ans;

        for (auto q : queries) {
            int firstCandleIndex =
                lower_bound(candlesIndex.begin(),
                            candlesIndex.end(),
                            q[0]) - candlesIndex.begin();

            int lastCandleIndex =
                upper_bound(candlesIndex.begin(),
                            candlesIndex.end(),
                            q[1]) - candlesIndex.begin() - 1;

            if (lastCandleIndex <= firstCandleIndex) {
                ans.push_back(0);
                continue;
            }

            int tempAns =
                candlesIndex[lastCandleIndex] -
                candlesIndex[firstCandleIndex] -
                (lastCandleIndex - firstCandleIndex);

            ans.push_back(tempAns);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> ans = obj.platesBetweenCandles(s, queries);

    for (int x : ans)
        cout << x << " ";

    cout << '\n';

    return 0;
}