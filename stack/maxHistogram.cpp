#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void maxHisto(vector<int> hieght)
{
  int n = hieght.size();
  vector<int> nsl(n);
  vector<int> nsr(n);
  stack<int> s;
  

  // next smaller left

  nsl[0] = -1; // because there is no element in the letf of first element;
  s.push(0);
  for (int i = 0; i < n; i++)
  {
    int curr = hieght[i];
    while (!s.empty() && curr <= hieght[s.top()])
    {
      s.pop();
    }
    if (s.empty())
    {
      nsl[i] = -1;
    }
    else
    {
      nsl[i] = s.top();
    }

    s.push(i);
  }
  while (!s.empty())
  {
    s.pop();
  }
  // next right smaller
  nsr[n - 1] = n;
  s.push(n - 1);

  for (int i = n - 2; i >= 0; i--)
  {
    int curr = hieght[i];
    while (!s.empty() && curr <= hieght[s.top()])
    {
      s.pop();
    }
    if (s.empty())
    {
      nsr[i] = n; // n
    }
    else
    {
      nsr[i] = s.top();
    }
    s.push(i);
  }
  int maxArea = 0;
  for (int i = 0; i < n; i++)
  {

    int ht = hieght[i];
    int width = nsr[i] - nsl[i] - 1;
    int area = ht * width;
    maxArea = max(maxArea, area);
  }
  cout << "Max area of histogram : " << maxArea << endl;
}

int main()
{
  vector<int> hieght = {2, 1, 5, 6, 2, 3};
  maxHisto(hieght);

  return 0;
}

/*
Largest Rectangle in Histogram

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
