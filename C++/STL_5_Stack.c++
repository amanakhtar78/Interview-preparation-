#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for stack (C++ STL)
// --------------------------------------
// ✅ stack<T>           → container adaptor (default uses deque as underlying container)
// ✅ push(x)            → insert element on top
// ✅ emplace(x)         → faster insert on top
// ✅ pop()              → remove top element
// ✅ top()              → access the top element
// ✅ size()             → number of elements
// ✅ empty()            → check if stack is empty
// ✅ swap(s1,s2)        → swap contents of two stacks
//
// ⚡ Properties:
// - LIFO (Last In First Out)
// - No iterators (cannot traverse directly)
// - Can only access the TOP element

void basicOfStack() {
    stack<int> st;

    // 👉 Push / Emplace
    st.push(10);     // {10}
    st.push(20);     // {10,20}
    st.emplace(30);  // {10,20,30}

    cout << "Top element: " << st.top() << endl;
    // OUTPUT: Top element: 30

    // 👉 Pop
    st.pop(); // removes 30 → {10,20}
    cout << "After pop, Top: " << st.top() << endl;
    // OUTPUT: After pop, Top: 20

    // 👉 Size & empty
    cout << "Size: " << st.size() << endl;
    cout << "Empty: " << st.empty() << endl;
    // OUTPUT:
    // Size: 2
    // Empty: 0

    // 👉 Swap
    stack<int> st2;
    st2.push(100);
    st2.push(200);

    st.swap(st2);

    cout << "After swap, Top of st: " << st.top() << endl;
    cout << "After swap, Top of st2: " << st2.top() << endl;
    // OUTPUT:
    // After swap, Top of st: 200
    // After swap, Top of st2: 20

    // 👉 Printing all elements (need a loop, no iterators!)
    cout << "Elements of st: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    // OUTPUT: Elements of st: 200 100
}

int main() {
    basicOfStack();
    return 0;
}
