#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxHisto(vector<int> hieght){

}

int main(){
    vector<int> hieght = {2,1,5,6,2,3};

    return 0;
}

/*
📌 Largest Rectangle in Histogram

Idea:
For every bar, assume it is the smallest height.
Expand left and right until a smaller bar appears.

Area = height[i] * width
Width = NSR[i] - NSL[i] - 1

--------------------------------------------------
Step 1: Find Next Smaller to Left (NSL)

- Traverse left → right
- Use monotonic increasing stack (store indices)
- While stack not empty AND height[stack.top()] >= height[i]
      pop
- If stack empty → NSL[i] = -1
  else → NSL[i] = stack.top()
- Push i

--------------------------------------------------
Step 2: Find Next Smaller to Right (NSR)

- Clear stack
- Traverse right → left
- While stack not empty AND height[stack.top()] >= height[i]
      pop
- If stack empty → NSR[i] = n
  else → NSR[i] = stack.top()
- Push i

(Note: use n instead of -1 for right boundary
because width = right - left - 1)

--------------------------------------------------
Step 3: Calculate Max Area

For each i:
    width = NSR[i] - NSL[i] - 1
    area = height[i] * width
    maxArea = max(maxArea, area)

Time: O(n)
Space: O(n)
*/
