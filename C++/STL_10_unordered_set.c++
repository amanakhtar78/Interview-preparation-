#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for unordered_set (C++ STL)
// -----------------------------------------------
// ✅ unordered_set<T>   → stores unique elements (no order)
// ✅ insert(x)          → insert element (O(1) avg)
// ✅ emplace(x)         → faster insert
// ✅ erase(x)           → erase element by value (O(1) avg)
// ✅ erase(it)          → erase by iterator
// ✅ find(x)            → returns iterator to element OR end() if not found
// ✅ count(x)           → returns 1 if element exists, else 0
// ✅ size(), empty(), clear()
// ✅ bucket_count(), load_factor() → hash table info
//
// ⚡ Properties:
// - Unique elements
// - Not sorted (order is unpredictable)
// - Backed by a hash table
// - Average O(1) insertion, deletion, lookup
// - Worst case O(n) (if many hash collisions)

void basicOfUnorderedSet() {
    unordered_set<int> us;

    // 👉 Insert
    us.insert(10);  // {10}
    us.insert(20);  // {10,20}
    us.insert(30);  // {10,20,30}
    us.insert(20);  // duplicate ignored → {10,20,30}
    us.emplace(40); // {10,20,30,40}

    cout << "Unordered Set elements: ";
    for (auto x : us) cout << x << " ";
    cout << endl;
    // ⚠️ OUTPUT order may vary (example): 40 30 20 10

    // 👉 Find
    auto it = us.find(20);
    if (it != us.end()) cout << "Found: " << *it << endl;
    else cout << "Not Found" << endl;
    // OUTPUT: Found: 20

    // 👉 Count
    cout << "Count(30): " << us.count(30) << endl;
    cout << "Count(50): " << us.count(50) << endl;
    // OUTPUT:
    // Count(30): 1
    // Count(50): 0

    // 👉 Erase by value
    us.erase(20); // remove 20
    cout << "After erase(20): ";
    for (auto x : us) cout << x << " ";
    cout << endl;
    // OUTPUT (order may vary): 40 30 10

    // 👉 Size & Empty
    cout << "Size: " << us.size() << endl;
    cout << "Empty: " << us.empty() << endl;
    // OUTPUT:
    // Size: 3
    // Empty: 0

    // 👉 Clear
    us.clear();
    cout << "After clear, Empty: " << us.empty() << endl;
    // OUTPUT: 1

    // 👉 Bucket info (for understanding hash table)
    unordered_set<int> u2 = {1,2,3,4,5,100};
    cout << "Bucket count: " << u2.bucket_count() << endl;
    cout << "Load factor: " << u2.load_factor() << endl;
    // OUTPUT (example values, vary by implementation):
    // Bucket count: 11
    // Load factor: 0.54
}

int main() {
    basicOfUnorderedSet();
    return 0;
}
