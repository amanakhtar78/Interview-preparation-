#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for map (C++ STL)
// --------------------------------------
// ✅ map<Key,Value>       → stores key-value pairs, keys are unique
// ✅ insert({k,v})        → insert key-value
// ✅ emplace(k,v)         → faster insert
// ✅ m[key] = v           → insert/update value for key
// ✅ erase(key)           → erase by key
// ✅ erase(it)            → erase by iterator
// ✅ erase(start,end)     → erase range
// ✅ find(key)            → returns iterator to key OR end()
// ✅ count(key)           → 1 if key exists, else 0
// ✅ size(), empty(), clear()
// ✅ lower_bound(key)     → >= key
// ✅ upper_bound(key)     → > key
//
// ⚡ Properties:
// - Keys are UNIQUE
// - Sorted by key (by default ascending order, uses Red-Black Tree)
// - All operations: O(log n)

void basicOfMap() {
    map<int, string> m;

    // 👉 Insert
    m.insert({1, "one"});
    m.emplace(2, "two");
    m[3] = "three";    // insert like array
    m[2] = "TWO";      // update value for existing key

    cout << "Map elements (sorted by key):" << endl;
    for (auto &p : m) {
        cout << p.first << " -> " << p.second << endl;
    }
    // OUTPUT:
    // 1 -> one
    // 2 -> TWO
    // 3 -> three

    // 👉 Find
    auto it = m.find(2);
    if (it != m.end()) cout << "Found key 2 with value: " << it->second << endl;
    // OUTPUT: Found key 2 with value: TWO

    // 👉 Count
    cout << "Count(3): " << m.count(3) << endl; // 1
    cout << "Count(5): " << m.count(5) << endl; // 0

    // 👉 Erase by key
    m.erase(1); // removes key=1
    cout << "After erase(1):" << endl;
    for (auto &p : m) cout << p.first << " -> " << p.second << endl;
    // OUTPUT:
    // 2 -> TWO
    // 3 -> three

    // 👉 Lower & Upper bound
    m[5] = "five"; // {2,TWO}, {3,three}, {5,five}
    cout << "Lower bound of 3: " << m.lower_bound(3)->first << endl; // 3
    cout << "Upper bound of 3: " << m.upper_bound(3)->first << endl; // 5

    // 👉 Size & Empty
    cout << "Size: " << m.size() << endl;
    cout << "Empty: " << m.empty() << endl;
    // OUTPUT:
    // Size: 3
    // Empty: 0

    // 👉 Clear
    m.clear();
    cout << "After clear, Empty: " << m.empty() << endl;
    // OUTPUT: 1
}

int main() {
    basicOfMap();
    return 0;
}
