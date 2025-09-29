#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for deque (C++ STL)
// --------------------------------------
// ✅ push_back(x)     → insert element at back
// ✅ push_front(x)    → insert element at front
// ✅ emplace_back(x)  → faster insert at back
// ✅ emplace_front(x) → faster insert at front
// ✅ pop_back()       → remove last element
// ✅ pop_front()      → remove first element
// ✅ operator[] / at(i) → random access (like vector)
// ✅ front() / back() → access first & last element
// ✅ insert(pos,x)    → insert before given position
// ✅ erase(pos)       → erase element at position
// ✅ erase(start,end) → erase range
// ✅ size()           → number of elements
// ✅ clear()          → delete all elements
// ✅ empty()          → check if deque is empty
// ✅ swap(d1,d2)      → swap two deques


void basicOfDeque() {
    // 👉 Basic insertions
    deque<int> dq;
    dq.push_back(10);     // {10}
    dq.push_front(20);    // {20,10}
    dq.emplace_back(30);  // {20,10,30}
    dq.emplace_front(40); // {40,20,10,30}

    cout << "Deque after basic insertions: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 20 10 30 

    // 👉 Random access
    cout << "Element at index 2: " << dq[2] << endl;
    // OUTPUT: Element at index 2: 10

    cout << "Element at index 1 using at(): " << dq.at(1) << endl;
    // OUTPUT: Element at index 1 using at(): 20

    // 👉 Front & Back
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    // OUTPUT: Front: 40, Back: 30

    // 👉 Pop operations
    dq.pop_back();   // {40,20,10}
    dq.pop_front();  // {20,10}

    cout << "After pops: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 20 10 

    // 👉 Insert
    auto it = dq.begin();
    advance(it, 1);   // move iterator to 2nd element
    dq.insert(it, 99); // {20,99,10}

    cout << "After insert: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 20 99 10 

    // 👉 Erase single element
    dq.erase(dq.begin()); // remove first element → {99,10}
    cout << "After erase first: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 99 10 

    // 👉 Erase range
    dq.push_back(50); // {99,10,50}
    dq.push_back(60); // {99,10,50,60}
    dq.erase(dq.begin() + 1, dq.begin() + 3); // remove {10,50} → {99,60}

    cout << "After erase range: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 99 60 

    // 👉 Size & empty
    cout << "Size: " << dq.size() << ", Empty: " << dq.empty() << endl;
    // OUTPUT: Size: 2, Empty: 0

    // 👉 Swap
    deque<int> dq2 = {1,2,3};
    dq.swap(dq2);
    cout << "After swap dq: ";
    for (auto x : dq) cout << x << " ";
    cout << endl;
    // OUTPUT: 1 2 3

    cout << "After swap dq2: ";
    for (auto x : dq2) cout << x << " ";
    cout << endl;
    // OUTPUT: 99 60 

    // 👉 Clear
    dq.clear(); // remove all
    cout << "After clear, Empty: " << dq.empty() << endl;
    // OUTPUT: After clear, Empty: 1
}

int main() {
    basicOfDeque();
    return 0;
}
