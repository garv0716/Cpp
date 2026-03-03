#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s = "  learn c++ stl fast  ";

    // basic string ops
    cout << "length: " << s.length() << '\n';
    cout << "substr(2,5): " << s.substr(2, 5) << '\n';

    // erase and insert
    string t = "hello world";
    t.erase(5, 1); // remove space
    t.insert(5, "_");
    cout << "after erase/insert: " << t << '\n';

    // stringstream split
    string line = "red,green,blue";
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ',')) tokens.push_back(token);

    cout << "tokens: ";
    for (const auto& w : tokens) cout << w << " ";
    cout << '\n';

    // transform to upper
    string word = "interview";
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    cout << "upper: " << word << '\n';

    return 0;
}
