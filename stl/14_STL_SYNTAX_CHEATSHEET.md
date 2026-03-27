# STL Syntax Cheatsheet (Fast Revision)

## Containers

```cpp
vector<int> v;
array<int, 5> a = {1,2,3,4,5};
deque<int> dq;
list<int> li;
forward_list<int> fl;
stack<int> st;
queue<int> q;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
set<int> s;
multiset<int> ms;
unordered_set<int> us;
map<string, int> mp;
multimap<string, int> mmp;
unordered_map<string, int> ump;
```

## Pair / Tuple

```cpp
pair<int, string> p = {1, "A"};
cout << p.first << p.second;

tuple<int, string, double> t = {1, "A", 2.5};
cout << get<0>(t);
```

## Common Algorithms

```cpp
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
rotate(v.begin(), v.begin()+k, v.end());
auto it = find(v.begin(), v.end(), x);
int c = count(v.begin(), v.end(), x);
bool ok = binary_search(v.begin(), v.end(), x);
auto lb = lower_bound(v.begin(), v.end(), x);
auto ub = upper_bound(v.begin(), v.end(), x);
int sum = accumulate(v.begin(), v.end(), 0);
```

## remove-erase idiom

```cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

## Iterators

```cpp
auto it = v.begin();
auto rit = v.rbegin();
advance(it, 2);
auto n = next(it);
auto p = prev(it);
auto d = distance(v.begin(), v.end());
```

## Lambdas

```cpp
auto cmp = [](int a, int b){ return a < b; };
sort(v.begin(), v.end(), cmp);
```

## Optional / Variant / Any

```cpp
optional<int> x = 10;
variant<int, string> v = "hello";
any a = 42;
```

## Time Complexity Quick
- `sort`: `O(n log n)`
- `map/set` insert/find: `O(log n)`
- `unordered_map/unordered_set` insert/find avg: `O(1)`
- `vector` random access: `O(1)`
- `vector` insert middle: `O(n)`
