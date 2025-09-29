#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for multiset (C++ STL)
// ------------------------------------------
// ✅ multiset<T>         → stores elements in sorted order (allows duplicates)
// ✅ insert(x)           → insert element (O(log n))
// ✅ emplace(x)          → faster insert
// ✅ erase(x)            → removes ALL occurrences of x
// ✅ erase(it)           → removes element at iterator
// ✅ erase(start,end)    → erase range
// ✅ find(x)             → returns iterator to one occurrence OR end()
// ✅ count(x)            → number of times x exists
// ✅ size(), empty(), clear()
// ✅ lower_bound(x)      → >= x element
// ✅ upper_bound(x)      → > x element
// ✅ equal_range(x)      → returns {lower_bound, upper_bound}
//
// ⚡ Properties:
// - Ordered (by default ascending)
// - Allows duplicates
// - Underlying: balanced BST (Red-Black tree)
// - All operations O(log n)

void basicOfMultiset() {
    multiset<int> ms;

    // 👉 Insert
    ms.insert(10);  // {10}
    ms.insert(20);  // {10,20}
    ms.insert(10);  // {10,10,20}
    ms.emplace(30); // {10,10,20,30}

    cout << "Multiset elements: ";
    for (auto x : ms) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 10 20 30

    // 👉 Count
    cout << "Count(10): " << ms.count(10) << endl;
    cout << "Count(50): " << ms.count(50) << endl;
    // OUTPUT:
    // Count(10): 2
    // Count(50): 0

    // 👉 Erase (all occurrences)
    ms.erase(10); // removes all 10s → {20,30}
    cout << "After erase(10): ";
    for (auto x : ms) cout << x << " ";
    cout << endl;
    // OUTPUT: 20 30

    // 👉 Erase single element using iterator
    ms.insert(20); // {20,20,30}
    auto it = ms.find(20); // points to first 20
    ms.erase(it);          // removes one 20 → {20,30}

    cout << "After erase(one 20): ";
    for (auto x : ms) cout << x << " ";
    cout << endl;
    // OUTPUT: 20 30

    // 👉 Lower & Upper bound
    ms.insert(25); // {20,25,30}
    cout << "Lower bound of 20: " << *ms.lower_bound(20) << endl; // 20
    cout << "Upper bound of 20: " << *ms.upper_bound(20) << endl; // 25

    // 👉 Equal range
    ms.insert(25); // {20,25,25,30}
    auto range = ms.equal_range(25);
    cout << "Equal range of 25: ";
    for (auto it = range.first; it != range.second; ++it) cout << *it << " ";
    cout << endl;
    // OUTPUT: 25 25

    // 👉 Size & Empty
    cout << "Size: " << ms.size() << endl;
    cout << "Empty: " << ms.empty() << endl;
    // OUTPUT:
    // Size: 4
    // Empty: 0

    // 👉 Clear
    ms.clear();
    cout << "After clear, Empty: " << ms.empty() << endl;
    // OUTPUT: 1
}

int main() {
    basicOfMultiset();
    return 0;
}
