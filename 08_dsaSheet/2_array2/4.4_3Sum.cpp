#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// BruteForce

// vector<vector<int>> threeSum(vector<int> &nums){
//     int n = nums.size();
//     vector <vector<int>> ans;
//     //for storing unique triplets
//     set <vector<int>> s;

//     for(int i = 0; i < n ; i ++){
//         for (int j = i+1; j < n ; j++){
//             for (int k = j+1; j < n; j++){
//                 if (nums[i] + nums[j]+ nums[k] == 0){
//                     vector<int> trip = { nums[i], nums[j], nums[k]};

//                     //before storing to set, we have to sort it 
//                     sort (trip.begin(), trip.end());

//                     //now we check is element already exist in set?
//                     if (s.find(trip) == s.end()){
//                         s.insert(trip);
//                         ans.push_back(trip);
//                     }
//                 }
//             }
//         }

//     }
//     return ans;

// }

// // better solution -> TLE O -> TC: O(n^2 log (uniqueTriplet))
// vector <vector<int>> threeSum(vector<int> &nums){
//     int n = nums.size();

//     set <vector<int>> uniqueTriplet; // 

//     for (int i = 0; i < n; i++){
//         int tar = -nums[i];
//         set<int> s;

//         for (int j = i+1; j < n; j ++){
//             int third = tar - nums[j];

//             if (s.find(tar) != s.end()){
//                 vector<int> trip = {nums[i], nums[j], third};
//                 sort(trip.begin(), trip.end());
//                 uniqueTriplet.insert(trip)
//             }
//             s.insert(nums[j]);
//         }
//     }
//     vector <vector <int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());
//     return ans;
// }
/*
// optimal apporach, Two pointer apporach
   1- nums -> sort
   2- then we start from extreme ends, i = 0, j = i+1, k = n-1;
   3- sum = num[i] + num [j] + num [k];
   4- if (sum > 0) -> k--;
   5- if (sum < 0) -> j++ 
   6- then there is pc i.e. perfect case where sum == 0;
   7 - In sorted data we have to make sure two things/-
     - sorted ->repeated values
     - add if (i > 0 && nums[i] == nums[i-1]) -> continue;
     - while(j < k && nums[j] == nums[j-1]) -> j++
*/
 
vector <vector<int>> threeSum(vector<int> &nums){
    int n = nums.size();
    vector<vector <int>> ans;

    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i ++){
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1 , k = n-1;

        while(j< k){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0){
                j++;
            }else if (sum > 0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]}){
                    j--; k--;

                    while(j < k && nums[j] == nums[j-1]) j++
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    return 0;
}


