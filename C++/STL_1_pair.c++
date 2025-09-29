#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for pair (C++ STL)
// --------------------------------------
// ✅ pair<T1,T2>         → stores two values (can be different types)
// ✅ first, second       → access elements
// ✅ make_pair(a,b)      → create a pair
// ✅ initialization      → {a,b} or pair<T,T>(a,b)
// ✅ nested pair         → pair inside another pair
// ✅ pair in container   → can be stored in vector/map/set
// ✅ comparison operators → pairs compare lexicographically (first, then second)

void basicOfPair() {
    // 👉 Simple initialization
    pair<int, string> p1 = {1, "apple"};
    cout << p1.first << " " << p1.second << endl;
    // OUTPUT: 1 apple

    // 👉 Using make_pair
    pair<int, double> p2 = make_pair(2, 3.14);
    cout << p2.first << " " << p2.second << endl;
    // OUTPUT: 2 3.14

    // 👉 Copy & assign
    pair<int, string> p3 = p1; // copy of p1
    cout << p3.first << " " << p3.second << endl;
    // OUTPUT: 1 apple

    // 👉 Nested pairs
    pair<int, pair<int, string>> nested = {10, {20, "banana"}};
    cout << nested.first << " " 
         << nested.second.first << " " 
         << nested.second.second << endl;
    // OUTPUT: 10 20 banana

    // 👉 Pair in vector
    vector<pair<int,string>> vec;
    vec.push_back({1,"one"});
    vec.emplace_back(2,"two");
    vec.emplace_back(3,"three");

    cout << "Vector of pairs:" << endl;
    for (auto &p : vec) {
        cout << p.first << " -> " << p.second << endl;
    }
    // OUTPUT:
    // 1 -> one
    // 2 -> two
    // 3 -> three

    // 👉 Pair comparison (lexicographic: first, then second)
    pair<int,int> a = {1, 2};
    pair<int,int> b = {1, 3};
    cout << (a < b) << endl;   // 1 (true, since 2 < 3)
    cout << (a == b) << endl;  // 0 (false)
    // OUTPUT:
    // 1
    // 0

    // 👉 Swapping pairs
    pair<int,string> x = {5,"hello"};
    pair<int,string> y = {10,"world"};
    swap(x,y);
    cout << x.first << " " << x.second << " | "
         << y.first << " " << y.second << endl;
    // OUTPUT: 10 world | 5 hello
}

int main() {
    basicOfPair();
    return 0;
}
