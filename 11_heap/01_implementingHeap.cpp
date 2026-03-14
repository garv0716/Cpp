#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec; 
    public:
      


     //pop
        void push(int val){ //O(logn)
            //step 1
            vec.push_back(val);
            //fix heap
            int x = vec.size() - 1; //child
            int parI = (x-1)/2;

            while (parI >= 0 && vec[x] > vec[parI]){ 
                swap(vec[x], vec[parI]);
                x = parI;
                parI = (x-1)/2;
            }

        }


        void heapify(int i){
            if (i >= vec.size()){
                return;
            }
            int l = 2*i+1; //left child
            int r = 2*i+2;//right child

            int maxI = i;
            if ( l < vec.size() && vec[l] > vec[maxI]){
                maxI = l;
            }
            if ( r < vec.size() && vec[r] < vec[maxI]){
                maxI = r;
            }

            swap(vec[i], vec[maxI]); // swap parent if their child is greater

            if (maxI != i){ // it is the case where swapping is happen with child
                heapify(maxI);
            }
        }
        
    //pop
        void pop (int i){
            //step 1
            swap (vec[0], vec[vec.size()-1]);

            //step 2 
            vec.pop_back();

            //step 3
            heapify(0); // O(logn)

        }

    //top
        int top(){ // O(1)
            return vec[0];
        }

    //empty
        bool empty(){
            //if vec size = 0 then heap =>0
            return vec.size() == 0;
        }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    while (!heap.empty()){
    cout << "Top = " << heap.top() << endl;
    heap.pop(0);
    // cout << "Top = " << heap.top() << endl;
    }
    return 0; 
}