#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


bool compare(pair<double, int> p1, pair<double, int>p2 ){
    return p1.first > p2.first; // ascsending ke liye < ka sign lagta hai, descending ke liye greater '>' k ka sign 
}

int fractionalKnapsack(vector<int>val , vector<int> wt , int w){
    int n = val.size();
    vector<pair<double, int>> ratio (n, make_pair(0.0, 0)); // pair (ratio, idx) -> (double,int)

    for (int i = 0; i < n; i++){
        double r = val[i]/ (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);
    int ans = 0; 
    for (int i = 0; i < n; i++){
        int idx = ratio[i].second;
        if (wt[idx] <= w){
            ans += val[idx];
            w -= wt[idx];
        }else{
            ans += ratio[i].first * w;
            w = 0; 
            break;
        }
    }
    cout << "max value = " << ans << endl;
    return ans;
}

int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};

    fractionalKnapsack(val, wt, w);

    int W = 50;
}


/*
 Fractional Knapsack (Greedy Approach)

Goal:
Maximize total value within given capacity W.
You are allowed to take FRACTION of an item.

-------------------------------------------------- GREEDY IDEA

Always pick the item with
maximum (value / weight) ratio first.

Because:
Higher ratio → more value per unit weight.

--------------------------------------------------
 Steps:

1️ Create a vector of pairs:
      (ratio, index)

   ratio = val[i] / wt[i]
   Store:
      pair<double, int> → (ratio, index)

2️ Sort the ratio vector
      in DESCENDING order
      (highest ratio first)

3️ Traverse sorted items:

   If wt[idx] <= W:
        take full item
        ans += val[idx]
        W -= wt[idx]

   Else:
        take fractional part
        ans += ratio * W
        W = 0
        break

--------------------------------------------------
Example

val = {60,100,120}
wt  = {10,20,30}
W   = 50

Ratios:
6, 5, 4

Pick:
10kg (60)
20kg (100)
20kg of 30kg item (80)

Max Value = 240

--------------------------------------------------
Time Complexity:
Sorting → O(n log n)

Space Complexity:
O(n)

--------------------------------------------------
Why Greedy Works?

Because taking highest value per unit weight
always gives optimal answer in fractional case.

(Note: This logic does NOT work for 0/1 Knapsack.)
*/
