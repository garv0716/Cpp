#include <iostream>
using namespace std;

int maxSum(int n){

    int sum = 0;
    
    while (n > 0){
        int d = n % 10;
        sum += d;
        n= n / 10;     
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << maxSum(n) << endl;
    return 0;
}