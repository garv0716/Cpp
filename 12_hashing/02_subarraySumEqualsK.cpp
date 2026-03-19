#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int subarrSumEqlK(vector<int> arr, int k){
    unordered_map<int , int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (m.count(sum-k)){
            ans += m[sum-k];
        }

        if (m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "Subarray Count = " << subarrSumEqlK(arr, k);
    return 0;
}