#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end){
    // sort on end time
    //A0 select
    cout<< "Selecting A0 \n";
    int count = 1;
    int currEndTime = end[0];

    for (int i = 1; i < end.size(); i++){
        if (start[i]>= currEndTime){ // non - overlapping
            cout<< "Selecting A " << i << endl;
            count ++;
            currEndTime = end[i];
        }

    }
    return count;
}

int main (){
    vector<int> start = {1,3,0,5,8,6};
    vector<int> end = {2,4,6,7,9,9}; //4
    cout << maxActivities(start, end) << endl;
    return 0;
}

/*
=> Apporach for activity Selection Problem
   (Variation: Maximum Meetings in One Room)

Goal:
Select the maximum number of non-overlapping activities.
A person can attend only one activity at a time.

--------------------------------------------------
GREEDY IDEA

Always select the activity that finishes earliest.
Why?
Because it leaves maximum time for future activities.

So:
1. Sort activities based on end time.
2. Pick the first activity.
3. For remaining activities:
      If start[i] >= last selected end time
         → select it

--------------------------------------------------
 Algorithm

1️ Assume activities are already sorted by end time.

2️ Select first activity:
      count = 1
      currEndTime = end[0]

3️ Loop from i = 1 to n-1:
      If start[i] >= currEndTime
            → select activity
            → count++
            → update currEndTime = end[i]

4️ Return count

--------------------------------------------------
Example

start = {1,3,0,5,8,6}
end   = {2,4,6,7,9,9}

Selected activities:
A0 → A1 → A3 → A4

Maximum = 4

--------------------------------------------------
Time Complexity  : O(n)   (if already sorted)
If sorting required → O(n log n)

Space Complexity : O(1)

*/
