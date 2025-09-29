#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for vector (C++ STL)
// --------------------------------------
// ✅ push_back(x)        → insert element at end
// ✅ emplace_back(x)     → faster insert at end (constructs in place)
// ✅ vector<pair<int,int>> → store pairs inside a vector
// ✅ initialize vector(n, val) → n copies of val
// ✅ initialize vector(n)     → n copies of 0
// ✅ copy constructor         → assign one vector to another
// ✅ begin(), end()           → iterators for start and "one past end"
// ✅ rbegin(), rend()         → reverse iterators
// ✅ erase(pos)               → remove element at given index
// ✅ erase(start,end)         → remove range
// ✅ insert(pos,val)          → insert single element
// ✅ insert(pos,n,val)        → insert n copies
// ✅ insert(pos,range_start,range_end) → insert another vector
// ✅ pop_back()               → remove last element
// ✅ swap(v1,v2)              → swap contents of two vectors
// ✅ clear()                  → remove all elements
// ✅ empty()                  → check if vector is empty
// ✅ size()                   → get number of elements


int basicOfVEctor() {
    // 👉 Basic insertions
    vector<int> v;
    v.push_back(1);          // v = {1}
    v.emplace_back(2);       // v = {1,2}
    cout << v[1] << " normal vector insert" << endl; 
    // OUTPUT: 2 normal vector insert

    // 👉 Storing pairs
    vector<pair<int, int>> vecPair;
    vecPair.push_back({1, 2});   // {(1,2)}
    vecPair.emplace_back(3, 4);  // {(1,2),(3,4)}

    for (int i = 0; i < vecPair.size(); i++) {
        cout << vecPair[i].first << " normal pair " << vecPair[i].second << endl;
        // OUTPUT:
        // 1 normal pair 2
        // 3 normal pair 4
    }

    // 👉 Initialize with fixed value
    vector<int> vFixedValues(5, 10); // {10,10,10,10,10}
    for (int x : vFixedValues) cout << x << " -> ";
    cout << endl;
    // OUTPUT: 10 -> 10 -> 10 -> 10 -> 10 -> 

    // 👉 Initialize with default values (all 0)
    vector<int> vAnyValues(5); // {0,0,0,0,0}
    for (int x : vAnyValues) cout << x << " -> ";
    cout << endl;
    // OUTPUT: 0 -> 0 -> 0 -> 0 -> 0 -> 

    // 👉 Copy constructor (assign vector)
    vector<int> newVector(vFixedValues); // copy
    for (int x : newVector) cout << x << " -> ";
    cout << endl;
    // OUTPUT: 10 -> 10 -> 10 -> 10 -> 10 -> 

    return 0;
}

void basicOFVectorInsertionAccess() {
    // 👉 Multiple insertions
    vector<int> v;
    v.push_back(1);  // {1}
    v.emplace_back(2); // {1,2}
    v.push_back(3);    // {1,2,3}
    v.emplace_back(4); // {1,2,3,4}
    v.push_back(5);    // {1,2,3,4,5}
    v.emplace_back(6); // {1,2,3,4,5,6}

    cout << v[0] << "-->" << v[1] << "-->" << v[2] << "-->" 
         << v[3] << "-->" << v[4] << "-->" << v[5] << endl;
    // OUTPUT: 1-->2-->3-->4-->5-->6

    // 👉 Iterators
    vector<int>::iterator it = v.begin();  
    cout << *(it) << endl;   // OUTPUT: 1
    it++;
    cout << *(it) << endl;   // OUTPUT: 2
    it += 2;
    cout << *(it) << endl;   // OUTPUT: 4
    cout << &(*it) << endl;  // prints address (differs every run)

    vector<int>::iterator itEND = v.end() - 1; // points to last element
    cout << *(itEND) << endl;  // OUTPUT: 6

    vector<int>::reverse_iterator itRBEGIN = v.rbegin(); // last element
    cout << *(itRBEGIN) << endl;  // OUTPUT: 6

    // 👉 Reverse traversal
    for (auto rit = v.rbegin(); rit != v.rend(); rit++) {
        cout << *rit << " ";  
    }
    cout << endl;
    // OUTPUT: 6 5 4 3 2 1 

    // 👉 Range-based for loop (C++11+)
    for (auto x : v) cout << x << " ";
    cout << endl;
    // OUTPUT: 1 2 3 4 5 6 

    // 👉 Erase single element
    v.erase(v.begin() + 1); // removes element at index 1 ("2")
    // v = {1,3,4,5,6}
    for (auto x : v) cout << x << " ";
    cout << endl;
    // OUTPUT: 1 3 4 5 6 

    // 👉 Erase range
    v.erase(v.begin() + 1, v.begin() + 2); // removes "3"
    // v = {1,4,5,6}
    for (auto x : v) cout << x << " ";
    cout << endl;
    // OUTPUT: 1 4 5 6 

    // 👉 Insert single and multiple
    vector<int> newV(2, 100);   // {100,100}
    newV.insert(newV.begin(), 300);        // {300,100,100}
    newV.insert(newV.begin() + 1, 2, 10);  // {300,10,10,100,100}
    for (auto x : newV) cout << x << " ";
    cout << endl;
    // OUTPUT: 300 10 10 100 100 

    // 👉 Insert another vector
    vector<int> copy(2, 50); // {50,50}
    newV.insert(newV.begin(), copy.begin(), copy.end());
    // newV = {50,50,300,10,10,100,100}
    for (auto x : newV) cout << x << " ";
    cout << endl;
    // OUTPUT: 50 50 300 10 10 100 100 

    // 👉 size()
    cout << newV.size() << endl;  // OUTPUT: 7

    // 👉 pop_back()
    newV.pop_back(); // removes last element
    // newV = {50,50,300,10,10,100}
    for (auto x : newV) cout << x << " ";
    cout << endl;
    // OUTPUT: 50 50 300 10 10 100 

    // 👉 swap()
    vector<int> v1 = {30, 40};
    vector<int> v2 = {40, 30};
    v1.swap(v2);
    for (auto x : v1) cout << x << " ";
    cout << endl;
    // OUTPUT: 40 30
    for (auto x : v2) cout << x << " ";
    cout << endl;
    // OUTPUT: 30 40

    // 👉 clear() + empty()
    v.clear(); // removes all
    cout << v.empty() << endl; // 1 (true)
}

int main() {
    basicOfVEctor();
    basicOFVectorInsertionAccess();
    return 0;
}
