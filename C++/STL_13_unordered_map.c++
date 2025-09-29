#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for unordered_map (C++ STL)
// -----------------------------------------------
// ✅ unordered_map<Key,Value>   → stores key-value pairs (unique keys)
// ✅ insert({k,v})              → insert key-value
// ✅ emplace(k,v)               → faster insert
// ✅ m[key] = v                 → insert/update value for key
// ✅ erase(key)                 → erase by key
// ✅ erase(it)                  → erase by iterator
// ✅ find(key)                  → iterator to element OR end()
// ✅ count(key)                 → 1 if exists else 0
// ✅ size(), empty(), clear()
// ✅ bucket_count(), load_factor() → info about hash table
//
// ⚡ Properties:
// - Keys are UNIQUE
// - No ordering (random order, depends on hashing)
// - Backed by hash table
// - Avg O(1) for insert/find/erase
// - Worst O(n) (if many collisions)

void basicOfUnorderedMap() {
    unordered_map<int, string> um;

    // 👉 Insert
    um.insert({1, "one"});
    um.emplace(2, "two");
    um[3] = "three";     // insert
    um[2] = "TWO";       // update value for key=2

    cout << "Unordered Map elements (order may vary):" << endl;
    for (auto &p : um) {
        cout << p.first << " -> " << p.second << endl;
    }
    // OUTPUT (order may vary):
    // 3 -> three
    // 2 -> TWO
    // 1 -> one

    // 👉 Find
    auto it = um.find(2);
    if (it != um.end()) cout << "Found key 2 with value: " << it->second << endl;
    else cout << "Not Found" << endl;
    // OUTPUT: Found key 2 with value: TWO

    // 👉 Count
    cout << "Count(3): " << um.count(3) << endl; // 1
    cout << "Count(5): " << um.count(5) << endl; // 0

    // 👉 Erase
    um.erase(1); // remove key=1
    cout << "After erase(1):" << endl;
    for (auto &p : um) cout << p.first << " -> " << p.second << endl;
    // OUTPUT (order may vary):
    // 3 -> three
    // 2 -> TWO

    // 👉 Size & Empty
    cout << "Size: " << um.size() << endl;
    cout << "Empty: " << um.empty() << endl;
    // OUTPUT:
    // Size: 2
    // Empty: 0

    // 👉 Clear
    um.clear();
    cout << "After clear, Empty: " << um.empty() << endl; // 1

    // 👉 Bucket info (hash table details)
    unordered_map<int, string> u2 = {{1,"a"}, {2,"b"}, {100,"c"}};
    cout << "Bucket count: " << u2.bucket_count() << endl;
    cout << "Load factor: " << u2.load_factor() << endl;
    // Example OUTPUT (varies):
    // Bucket count: 7
    // Load factor: 0.42
}

int main() {
    basicOfUnorderedMap();
    return 0;
}
