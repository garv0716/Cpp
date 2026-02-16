/*
Notes: Using pair in C++ (STL)

-pair:
- STL container used to store TWO related values together.
- Syntax:
      pair<datatype1, datatype2> p;

Example:
      pair<int,int> p = {start, end};

p.first  → first value
p.second → second value

--------------------------------------------------
- Why use pair?

Instead of:
    start = [0,1,3]
    end   = [9,2,4]

We combine them as:
    (0,9), (1,2), (3,4)

This makes sorting and processing easier.

--------------------------------------------------

-Vector of pairs:

Syntax:
    vector<pair<datatype1, datatype2>> name(size, make_pair(0,0));

Example:
    vector<pair<int,int>> activity(3, make_pair(0,0));

Now each element stores:
    activity[i].first  → start
    activity[i].second → end

--------------------------------------------------

Useful in:
- Activity Selection
- Sorting based on second value
- Storing coordinates
- Competitive Programming
*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (pair <int, int> p1, pair<int, int> p2){
  return p1.second < p2.second; // ascending -> end
  return p1.second > p2.second; // descending -> end


  // return p1.first < p2.first;  // ascending -> start
  // return p1.first < p2.first;  // descending -> start
}

int main(){

  vector<int> start = {0,1,2};
  vector<int> end = {9,2,4};

  vector<pair<int,int>> activity (3, make_pair(0,0)); 
  activity[0] = make_pair(0,9);
  activity[1] = make_pair(1,2);
  activity[2] = make_pair(2,4);

  for (int i = 0; i < activity.size(); i++){  
    cout<< i << " " << activity[i].first << "," << activity[i].second << endl;
  }
  
  cout << "-------sorted-------"<< endl;

  sort(activity.begin(), activity.end(), compare);

   for (int i = 0; i < activity.size(); i++){  
    cout<< i << " " << activity[i].first << "," << activity[i].second << endl;
  }
  return 0;
}

/*
Using pair + Custom Comparator with sort()

Goal:
Store activity start and end time together
and sort them based on requirement.

--------------------------------------------------
 pair<int,int>

- first  → start time
- second → end time

Vector of pairs:
vector<pair<int,int>> activity;

Each element:
(start, end)

--------------------------------------------------
 compare() Function

Used by sort() to decide ordering.

return p1.second < p2.second;
→ Sort in ascending order of end time

(Useful in Activity Selection problem)

Note:
Only ONE return statement should be active.
Other return lines are just alternatives
for different sorting criteria.

--------------------------------------------------
 Main Logic

1️ Create vector of pairs:
   activity[i] = make_pair(start, end)

2️ Print original order

3️ Sort using:
   sort(activity.begin(), activity.end(), compare);

4️ Print sorted order

--------------------------------------------------
Time Complexity:
Sorting → O(n log n)

Space Complexity:
O(n)

*/
