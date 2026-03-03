# C++ STL Master Guide (Simple Language)

This folder is designed as a complete STL revision pack for interviews and practice.

## What is STL?
STL = Standard Template Library.
It gives ready-made generic components:
- Containers (data store karne ke liye)
- Iterators (traverse karne ke liye)
- Algorithms (sort/search/count etc.)
- Function objects / lambdas
- Utility types (`pair`, `tuple`, `optional`, etc.)

## STL ke 4 main pillars
1. Containers
2. Iterators
3. Algorithms
4. Function objects (functors/lambdas)

## File Order (start here)
1. `01_pair_and_tuple.cpp`
2. `02_sequence_containers.cpp`
3. `03_container_adapters.cpp`
4. `04_associative_containers.cpp`
5. `05_unordered_containers.cpp`
6. `06_iterators.cpp`
7. `07_algorithms_part1.cpp`
8. `08_algorithms_part2.cpp`
9. `09_numeric_and_bit.cpp`
10. `10_lambdas_and_functors.cpp`
11. `11_utility_types.cpp`
12. `12_string_and_stringstream.cpp`
13. `13_smart_pointers.cpp`
14. `14_STL_SYNTAX_CHEATSHEET.md`

## Quick interview theory

### 1) vector vs list
- `vector`: contiguous memory, fast random access `O(1)`.
- `list`: doubly linked list, random access slow, insert/delete in middle easy.

### 2) map vs unordered_map
- `map`: sorted keys, red-black tree, `O(log n)`.
- `unordered_map`: hash table, average `O(1)`, order not fixed.

### 3) set vs unordered_set
- `set`: sorted unique values.
- `unordered_set`: unique values but no sorted order.

### 4) multiset/multimap
- Duplicates allowed.

### 5) priority_queue
- By default max-heap.
- Min-heap banane ke liye `greater<int>`.

### 6) lower_bound / upper_bound
- `lower_bound`: first index/value >= x
- `upper_bound`: first index/value > x

### 7) remove-erase idiom
- `remove` element ko logically end me shift karta hai, container size same rehta hai.
- Actual delete ke liye `.erase(newEnd, end())` use karo.

### 8) Iterator invalidation
- `vector` me reallocation hone par old iterators invalid ho sakte hain.
- `list` me mostly iterators stable rehte hain.

### 9) Time complexity high-yield
- `vector` push_back: amortized `O(1)`
- `map` insert/find: `O(log n)`
- `unordered_map` insert/find: avg `O(1)`
- `set` insert/find: `O(log n)`
- `sort`: `O(n log n)`

### 10) Best practice
- Prefer STL containers over raw arrays for safety and readability.
- Use `auto` + range-based loops for clean code.
- Use `const` references to avoid unnecessary copy.

## Compile examples
Run all cpp files quickly:

```bash
g++ -std=c++17 07_stl/01_pair_and_tuple.cpp -o /tmp/stl01 && /tmp/stl01
```

or loop:

```bash
for f in 07_stl/*.cpp; do
  g++ -std=c++17 "$f" -o /tmp/"$(basename "$f" .cpp)" || break
  /tmp/"$(basename "$f" .cpp)"
done
```
