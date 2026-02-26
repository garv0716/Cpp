/*
-> now we have to also return the index of the job 
 - we have to return the sequence of the how
 *NOTES: kuch kuch cases mai ho sakta hai hume multiple value ek sath rakhna ho sortin krrne se palhe, to unhe class ki form mai object mai likh dakte hai
         &then we use emplace back function there.

 * SORTING: for sorting we use  
            -> [] : capture list  
            -> () : lamda function
            -> [](Job &a, Job&b){
                  return a.profit > b.profit;
                }
*/          


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
