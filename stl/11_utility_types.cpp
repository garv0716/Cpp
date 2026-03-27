#include <any>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <variant>
using namespace std;

optional<int> safeDivide(int a, int b) {
    if (b == 0) return nullopt;
    return a / b;
}

int main() {
    // pair
    pair<string, int> p = {"age", 21};
    cout << "pair: " << p.first << "=" << p.second << '\n';

    // tuple
    tuple<int, string, double> t = {1, "Alice", 99.4};
    cout << "tuple second value: " << get<1>(t) << '\n';

    // optional
    auto ans = safeDivide(10, 2);
    if (ans.has_value()) cout << "optional divide result: " << ans.value() << '\n';

    // variant
    variant<int, string> v;
    v = 10;
    cout << "variant int: " << get<int>(v) << '\n';
    v = string("hello");
    cout << "variant string: " << get<string>(v) << '\n';

    // any
    any x = 42;
    cout << "any int: " << any_cast<int>(x) << '\n';
    x = string("STL");
    cout << "any string: " << any_cast<string>(x) << '\n';

    return 0;
}
