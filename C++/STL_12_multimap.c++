#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for multimap (C++ STL)
// -------------------------------------------
// ✅ multimap<Key,Value>   → stores key-value pairs, keys are NOT unique
// ✅ insert({k,v})         → insert element (duplicates allowed)
// ✅ emplace(k,v)          → faster insert
// ❌ operator[] not available (cannot directly do m[key])
// ✅ erase(key)            → erase all entries with that key
// ✅ erase(it)             → erase single entry by iterator
// ✅ find(key)             → returns iterator to first element with key OR end()
// ✅ count(key)            → returns number of elements with given key
// ✅ equal_range(key)      → gives pair of iterators [lower_bound, upper_bound)
// ✅ size(), empty(), clear()
//
// ⚡ Properties:
// - Keys can repeat (unlike map).
// - Sorted by key (ascending by default).
// - All operations: O(log n).

void basicOfMultiMap() {
    multimap<int, string> mm;

    // 👉 Insert
    mm.insert({1, "one"});
    mm.insert({2, "two"});
    mm.insert({2, "second-two"});
    mm.insert({3, "three"});
    mm.emplace(3, "third-three");

    cout << "Multimap elements (sorted by key, duplicates allowed):" << endl;
    for (auto &p : mm) {
        cout << p.first << " -> " << p.second << endl;
    }
    // OUTPUT:
    // 1 -> one
    // 2 -> two
    // 2 -> second-two
    // 3 -> three
    // 3 -> third-three

    // 👉 Count
    cout << "Count(2): " << mm.count(2) << endl; // 2
    cout << "Count(3): " << mm.count(3) << endl; // 2
    cout << "Count(5): " << mm.count(5) << endl; // 0

    // 👉 Find (first occurrence of key)
    auto it = mm.find(2);
    if (it != mm.end()) cout << "Found key 2 with value: " << it->second << endl;
    // OUTPUT: Found key 2 with value: two

    // 👉 Erase all with a key
    mm.erase(2); // removes both {2, "two"} and {2, "second-two"}
    cout << "After erase(2):" << endl;
    for (auto &p : mm) cout << p.first << " -> " << p.second << endl;
    // OUTPUT:
    // 1 -> one
    // 3 -> three
    // 3 -> third-three

    // 👉 Equal range (all values for a given key)
    auto range = mm.equal_range(3);
    cout << "Equal range for key=3:" << endl;
    for (auto itr = range.first; itr != range.second; itr++) {
        cout << itr->first << " -> " << itr->second << endl;
    }
    // OUTPUT:
    // 3 -> three
    // 3 -> third-three

    // 👉 Size & Empty
    cout << "Size: " << mm.size() << endl;
    cout << "Empty: " << mm.empty() << endl;

    // 👉 Clear
    mm.clear();
    cout << "After clear, Empty: " << mm.empty() << endl; // 1
}

int main() {
    basicOfMultiMap();
    return 0;
}
