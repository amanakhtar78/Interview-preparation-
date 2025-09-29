#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for list (C++ STL)
// --------------------------------------
// ✅ push_back(x)     → insert element at end
// ✅ push_front(x)    → insert element at front
// ✅ emplace_back(x)  → faster insert at end (constructs in place)
// ✅ emplace_front(x) → faster insert at front
// ✅ insert(pos,x)    → insert before given position
// ✅ erase(pos)       → remove element at given position
// ✅ remove(val)      → remove ALL occurrences of val
// ✅ pop_back()       → remove last element
// ✅ pop_front()      → remove first element
// ✅ front() / back() → access first & last element
// ✅ size()           → number of elements
// ✅ clear()          → delete all elements
// ✅ empty()          → check if list is empty
// ✅ reverse()        → reverse order
// ✅ sort()           → sort ascending
// ✅ unique()         → remove consecutive duplicates
// ✅ merge(other)     → merge two sorted lists
// ✅ splice(pos, other) → move nodes from another list


void basicOfList() {
    // 👉 Basic insertion
    list<int> lst;
    lst.push_back(10);   // {10}
    lst.push_front(20);  // {20,10}
    lst.emplace_back(30); // {20,10,30}
    lst.emplace_front(40); // {40,20,10,30}

    cout << "List after basic insertions: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 20 10 30 

    // 👉 Insert at specific position
    auto it = lst.begin();
    advance(it, 2);        // move iterator to 3rd element
    lst.insert(it, 99);    // {40,20,99,10,30}

    cout << "After insert at pos 2: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 20 99 10 30 

    // 👉 Erase element at position
    it = lst.begin();
    advance(it, 1);        // 2nd element
    lst.erase(it);         // removes "20" → {40,99,10,30}

    cout << "After erase pos 1: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 99 10 30 

    // 👉 Remove by value
    lst.push_back(99);     // {40,99,10,30,99}
    lst.remove(99);        // remove all 99 → {40,10,30}

    cout << "After remove(99): ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 10 30 

    // 👉 Pop operations
    lst.pop_front();       // remove first → {10,30}
    lst.pop_back();        // remove last  → {10}

    cout << "After pop operations: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 

    // 👉 front() & back()
    lst.push_back(50);     // {10,50}
    cout << "Front: " << lst.front() << ", Back: " << lst.back() << endl;
    // OUTPUT: Front: 10, Back: 50

    // 👉 size, empty
    cout << "Size: " << lst.size() << ", Empty: " << lst.empty() << endl;
    // OUTPUT: Size: 2, Empty: 0

    // 👉 reverse
    lst.push_front(70); // {70,10,50}
    lst.reverse();      // {50,10,70}
    cout << "After reverse: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 50 10 70 

    // 👉 sort
    lst.push_back(20); // {50,10,70,20}
    lst.sort();        // {10,20,50,70}
    cout << "After sort: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 20 50 70 

    // 👉 unique (removes consecutive duplicates)
    lst.push_back(70); // {10,20,50,70,70}
    lst.unique();      // {10,20,50,70}
    cout << "After unique: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 20 50 70 

    // 👉 merge (both must be sorted)
    list<int> other = {15, 25, 65};
    lst.merge(other); // lst={10,15,20,25,50,65,70}, other becomes empty

    cout << "After merge: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 15 20 25 50 65 70 

    // 👉 splice (move elements)
    list<int> another = {100, 200};
    auto pos = lst.begin();
    advance(pos, 3); // 4th position
    lst.splice(pos, another); // move all from another into lst

    cout << "After splice: ";
    for (auto x : lst) cout << x << " ";
    cout << endl;
    // OUTPUT: 10 15 20 100 200 25 50 65 70 

    // 👉 clear()
    lst.clear(); // removes all elements
    cout << "After clear, Empty: " << lst.empty() << endl;
    // OUTPUT: After clear, Empty: 1
}


int main() {
    basicOfList();
    return 0;
}
