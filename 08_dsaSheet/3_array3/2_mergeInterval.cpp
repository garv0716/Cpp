#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        int index = 0;

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] <= intervals[index][1]) {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else {
                index++;
                intervals[index] = intervals[i];
            }
        }

        intervals.resize(index + 1);

        return intervals;
    }

int main() {

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    merge(intervals);
    for(auto interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}


/*
===========================================================
MERGE INTERVALS (IN-PLACE APPROACH)
===========================================================

-------------------
WHAT is the problem?
-------------------
Given a list of intervals where each interval has:
[start, end]

We need to merge all overlapping intervals.

Example:
Input:  [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

------------------------------------------------------------
WHY do we sort the intervals?
------------------------------------------------------------
Overlapping intervals may not be adjacent.

Example:
[[4,7],[1,4]]

After sorting:
[[1,4],[4,7]]

Sorting ensures overlapping intervals come next to each other,
making merging easy.

C++ sort on vector<vector<int>> sorts lexicographically:
First compares start
If equal, compares end

Time Complexity of sorting = O(n log n)

------------------------------------------------------------
HOW does the algorithm work?
------------------------------------------------------------

Step 1: Sort intervals based on start time

Step 2: Use index pointer
index represents position of last merged interval

Initially:
index = 0 → first interval is considered merged

Step 3: Traverse intervals from i = 1 to n-1

For each interval, check overlap:

Overlap condition:
intervals[i][0] <= intervals[index][1]

Meaning:
current.start <= lastMerged.end

------------------------------------------------------------
Case 1: If overlapping
------------------------------------------------------------

Merge intervals by updating end time:

intervals[index][1] =
max(intervals[index][1], intervals[i][1])

Example:
[1,3] and [2,6]
Merge → [1,6]

------------------------------------------------------------
Case 2: If NOT overlapping
------------------------------------------------------------

Move index forward and store new interval:

index++
intervals[index] = intervals[i]

------------------------------------------------------------
Step 4: Resize the array
------------------------------------------------------------

Why resize?

Because merged intervals are stored in first (index+1) positions.
Remaining elements are garbage.

intervals.resize(index + 1)

------------------------------------------------------------
DRY RUN Example
------------------------------------------------------------

Input:
[[1,3],[2,6],[8,10],[15,18]]

After sorting:
[[1,3],[2,6],[8,10],[15,18]]

index = 0

i = 1 → 2 <= 3 → overlap → merge → [1,6]

i = 2 → 8 > 6 → no overlap → index = 1

i = 3 → 15 > 10 → no overlap → index = 2

Final result:
[[1,6],[8,10],[15,18]]

------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Sorting: O(n log n)
Traversal: O(n)

Total: O(n log n)

------------------------------------------------------------
SPACE COMPLEXITY
------------------------------------------------------------

O(1) extra space (in-place solution)

------------------------------------------------------------
EDGE CASES to remember
------------------------------------------------------------

1. Single interval
[[1,5]]
Output: [[1,5]]

2. Fully overlapping
[[1,10],[2,3],[4,8]]
Output: [[1,10]]

3. No overlap
[[1,2],[3,4],[5,6]]

4. Touching intervals
[[1,4],[4,5]]
Output: [[1,5]]

Because:
4 <= 4 → overlap

------------------------------------------------------------
POINTS TO REMEMBER (INTERVIEW IMPORTANT)
------------------------------------------------------------

1. Always sort intervals first
2. Use <= for overlap condition
3. index tracks last merged interval
4. Merge by updating end time
5. Resize array at the end
6. This is optimal solution with O(1) extra space

------------------------------------------------------------
INTERVIEW ONE-LINE EXPLANATION
------------------------------------------------------------

Sort intervals by start time, then traverse and merge
overlapping intervals in-place using an index pointer.

===========================================================
*/