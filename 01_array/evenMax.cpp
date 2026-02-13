#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxElement = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            if(maxElement == -1 || arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }
    }

    cout << maxElement;

    return 0;
}
