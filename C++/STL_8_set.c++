#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for set (C++ STL)
// --------------------------------------
// ✅ set<T>              → stores unique elements in sorted order
// ✅ insert(x)           → insert element (O(log n))
// ✅ emplace(x)          → faster insert (O(log n))
// ✅ erase(x)            → erase by value (O(log n))
// ✅ erase(it)           → erase by iterator
// ✅ erase(start,end)    → erase range
// ✅ find(x)             → returns iterator to element OR end() if not found
// ✅ count(x)            → returns 1 if element exists, else 0
// ✅ size(), empty(), clear()
// ✅ lower_bound(x)      → >= x element
// ✅ upper_bound(x)      → > x element
// ✅ begin(), end()      → iterators
// ✅ rbegin(), rend()    → reverse iterators
//
// ⚡ Properties:
// - Ordered (by default ascending)
// - No duplicates
// - Underlying: balanced BST (Red-Black tree)
// - All operations O(log n)

void basicOfSet() {
    set<int> s;

    // 👉 Insert
    s.insert(10);  // {10}
    s.insert(40);  // {10,40}
    s.insert(20);  // {10,20,40}
    s.insert(20);  // duplicate ignored → {10,20,40}
    s.emplace(30); // {10,20,30,40}

    cout << "Set elements: ";
    for (auto x : s) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 20 30 40

    // 👉 Find
    auto it = s.find(20);
    if (it != s.end()) cout << "Found: " << *it << endl;
    else cout << "Not Found" << endl;
    // OUTPUT: Found: 20

    // 👉 Count
    cout << "Count(20): " << s.count(20) << endl;
    cout << "Count(50): " << s.count(50) << endl;
    // OUTPUT:
    // Count(20): 1
    // Count(50): 0

    // 👉 Erase by value
    s.erase(20); // {10,30,40}
    cout << "After erase(20): ";
    for (auto x : s) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 30 40

    // 👉 Erase by iterator
    auto it2 = s.find(30);
    s.erase(it2); // {10,40}
    cout << "After erase(iterator to 30): ";
    for (auto x : s) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 40

    // 👉 Lower & Upper bound
    s.insert(25); // {10,25,40}
    cout << "Lower bound of 20: " << *s.lower_bound(20) << endl; // 25
    cout << "Upper bound of 25: " << *s.upper_bound(25) << endl; // 40

    // 👉 Size & Empty
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;
    // OUTPUT:
    // Size: 3
    // Empty: 0

    // 👉 Clear
    s.clear();
    cout << "After clear, Empty: " << s.empty() << endl;
    // OUTPUT: 1
}

int main() {
    basicOfSet();
    return 0;
}
