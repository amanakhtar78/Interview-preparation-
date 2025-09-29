#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for priority_queue (C++ STL)
// -----------------------------------------------
// ✅ priority_queue<T>                  → max-heap (largest element at top)
// ✅ priority_queue<T, vector<T>, greater<T>> → min-heap (smallest at top)
// ✅ push(x)        → insert element
// ✅ emplace(x)     → faster insert
// ✅ pop()          → remove top element
// ✅ top()          → access the largest/smallest element
// ✅ size()         → number of elements
// ✅ empty()        → check if empty
// ✅ swap(pq1,pq2)  → swap contents
//
// ⚡ Properties:
// - By default: MAX HEAP
// - Elements are arranged by priority, not insertion order
// - No iterators (cannot traverse directly)
// - To print all, must pop one by one

void basicOfPriorityQueue() {
    // 👉 Max Heap (default)
    priority_queue<int> pq;
    pq.push(10);    // {10}
    pq.push(50);    // {50,10}
    pq.emplace(20); // {50,10,20}

    cout << "Max-Heap Top: " << pq.top() << endl;
    // OUTPUT: 50

    pq.pop(); // removes 50 → {20,10}
    cout << "After pop, Top: " << pq.top() << endl;
    // OUTPUT: 20

    // 👉 Print all (must pop)
    cout << "Max-Heap Elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // OUTPUT: 20 10

    // 👉 Min Heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(100); // {100}
    minpq.push(30);  // {30,100}
    minpq.push(50);  // {30,100,50}

    cout << "Min-Heap Top: " << minpq.top() << endl;
    // OUTPUT: 30

    minpq.pop(); // removes 30 → {50,100}
    cout << "After pop, Top: " << minpq.top() << endl;
    // OUTPUT: 50

    cout << "Min-Heap Elements: ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << endl;
    // OUTPUT: 50 100

    // 👉 Custom comparator (pair - sort by first element descending, second ascending)
    priority_queue<pair<int,int>> pqPairs;
    pqPairs.push({1,100});
    pqPairs.push({2,50});
    pqPairs.push({2,80});

    cout << "Priority Queue of pairs (max-heap by first):" << endl;
    while (!pqPairs.empty()) {
        cout << pqPairs.top().first << " " << pqPairs.top().second << endl;
        pqPairs.pop();
    }
    // OUTPUT:
    // 2 80
    // 2 50
    // 1 100
}

int main() {
    basicOfPriorityQueue();
    return 0;
}
