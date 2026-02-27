#include <iostream>
#include <vector>
using namespace std;

class Job{
public:
    int idx;
    int deadline;
    int profit;

    // constructor
    Job(int idx, int deadline, int profit){
        this-> idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int , int>> pairs){

    // now we have to create a vector in which the Job class object is there
    int n = pairs.size();
    vector<Job> jobs;

    for(int i = 0; i < n; i ++){

        // here we use emplace_back, because in emplace back we directly pass our values, if we do pushback we have to create an new object and then have to pass an object or we have to store this in variable then push back
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); // idx, deadline, profit
    }
    sort(jobs.begin(), jobs.end(), [](Job &a, Job&b){

        //sort in descending order on the basis of profit
        return a.profit > b.profit;
    });

    int profit = jobs[0].profit;
    int safeDeadline = 2;

    cout << "Selecting Job : "<< jobs[0].idx << endl;

    for (int i = 1; i < jobs.size(); i++){
        if (jobs[i].deadline > safeDeadline){
            cout << "Selecting Job : " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline ++;
        }    
    }
    
    cout << "Max Profit  = " << profit << endl;
    return profit;
}

int main (){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    maxProfit(jobs);
    return 0;
}


/*
# What is the Problem?

We are given jobs with:
deadline → last time to complete job  
profit → profit earned after completing job  

Each job takes 1 unit time.

Goal:

• Select jobs  
• Follow deadline constraint  
• Maximize total profit  
---
# Intuition

To maximize profit, we should always select the job with highest profit first.
Because:

Selecting high profit job early gives maximum gain.

This is Greedy Thinking:

"Make best choice at current step"

---

# Approach (Step by Step)

Step 1: Store job data using Class

We store:

• index  
• deadline  
• profit  

inside Job class.

---

Step 2: Sort jobs by profit (Descending)

Highest profit job comes first.

Because we want maximum profit.

---

Step 3: Select first job

First job has highest profit.

Add its profit.

---

Step 4: Check remaining jobs

Condition:

```cpp
if(jobs[i].deadline > safeDeadline)
```

Meaning:

Job can be completed before deadline.

If yes:

• select job  
• add profit  
• increase safeDeadline  

---

Step 5: Return total profit

---

# Why we use Class?

Class helps to store multiple values together.

Without class, we would need multiple arrays.

Bad approach:

deadline[]
profit[]
index[]

Good approach:

Job object stores everything together.

Cleaner and easier.

---

# Class and Object Explanation (Important)

Class is blueprint.

Example:

```cpp
class Job {
public:
    int idx;
    int deadline;
    int profit;
};
```

Object is real instance.

Example:

```cpp
Job j1(0,4,20);
```

This creates job with:

idx = 0  
deadline = 4  
profit = 20  

---

# Why we use emplace_back?

```cpp
jobs.emplace_back(i, deadline, profit);
```

It directly creates object inside vector.

Faster than push_back.

---

# Why we sort by profit?

Because our goal is:

Maximize profit.

Higher profit jobs should be selected first.

This is Greedy Strategy.

---

# Why safeDeadline is used?

It represents next free time slot.

We check:

```cpp
deadline > safeDeadline
```

Meaning job can still be completed.

---

# Dry Run Example

Input:

(4,20)  
(1,10)  
(1,40)  
(1,30)  

After sorting:

(1,40)  
(1,30)  
(4,20)  
(1,10)  

Selected:

Job with profit 40  
Job with profit 20  
Total Profit = 60
---
# Time Complexity

Sorting takes:
O(n log n)

Loop takes:
O(n)

Final:
O(n log n)
---
# Space Complexity
O(n)
For storing jobs.
---
# Why this is Greedy?
Because we always pick best available option first.
Best option = highest profit job
---
*/