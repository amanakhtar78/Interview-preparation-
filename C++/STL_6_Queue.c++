#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for queue (C++ STL)
// --------------------------------------
// ✅ queue<T>           → container adaptor (default uses deque underneath)
// ✅ push(x)            → insert element at back
// ✅ emplace(x)         → faster insert at back
// ✅ pop()              → remove element from front
// ✅ front()            → access first element
// ✅ back()             → access last element
// ✅ size()             → number of elements
// ✅ empty()            → check if queue is empty
// ✅ swap(q1,q2)        → swap contents of two queues
//
// ⚡ Properties:
// - FIFO (First In First Out)
// - Only front() and back() accessible
// - No iterators (cannot directly traverse)

void basicOfQueue() {
    queue<int> q;

    // 👉 Push / Emplace
    q.push(10);     // {10}
    q.push(20);     // {10,20}
    q.emplace(30);  // {10,20,30}

    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;
    // OUTPUT: Front: 10, Back: 30

    // 👉 Pop
    q.pop();  // removes 10 → {20,30}
    cout << "After pop, Front: " << q.front() << endl;
    // OUTPUT: After pop, Front: 20

    // 👉 Size & empty
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;
    // OUTPUT:
    // Size: 2
    // Empty: 0

    // 👉 Swap
    queue<int> q2;
    q2.push(100);
    q2.push(200);

    q.swap(q2);

    cout << "After swap, Front of q: " << q.front() << endl;
    cout << "After swap, Front of q2: " << q2.front() << endl;
    // OUTPUT:
    // After swap, Front of q: 100
    // After swap, Front of q2: 20

    // 👉 Printing all elements (need loop, no iterators!)
    cout << "Elements of q: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    // OUTPUT: Elements of q: 100 200
}

int main() {
    basicOfQueue();
    return 0;
}
