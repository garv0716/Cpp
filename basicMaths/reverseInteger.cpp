#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int x) {
    long long rev = 0;

    while (x != 0) {
        int d = x % 10;
        rev = rev * 10 + d;
        x = x / 10;

        if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }
    }
    return (int)rev;
}

int main() {
    int x;
    cout << "Enter the number which you want to reverse" << endl;
    cin >> x;
    cout << reverseNumber(x) << endl;
    return 0;
}
