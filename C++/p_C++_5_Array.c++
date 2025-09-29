#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for Normal Arrays (C++)
// -----------------------------------------
// ✅ Fixed size, stored in contiguous memory
// ✅ Index-based access (0-based)
// ✅ Size must be known at compile time (or with const in C++)
// ✅ No built-in methods (unlike vector), but <algorithm> provides helpers
// ✅ Common utilities:
//    - Access: arr[i]
//    - sizeof(arr) / sizeof(arr[0]) → length
//    - sort(arr, arr+n)
//    - reverse(arr, arr+n)
//    - *max_element, *min_element
//    - accumulate(arr, arr+n, init)
//    - find(arr, arr+n, value)

void basicOfArray() {
    // 👉 Initialization
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // length of array
    cout << "Array size: " << n << endl;

    // 👉 Access
    cout << arr[0] << " " << arr[4] << endl; 
    // 10 50

    // 👉 Update
    arr[2] = 99;
    cout << arr[2] << endl; 
    // 99

    // 👉 Traversal
    cout << "Using for loop: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 👉 Range-based for loop (C++11+)
    cout << "Range-based loop: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // 👉 Sort
    sort(arr, arr + n);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 👉 Reverse
    reverse(arr, arr + n);
    cout << "Reversed: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 👉 Max / Min
    cout << "Max: " << *max_element(arr, arr+n) << endl;
    cout << "Min: " << *min_element(arr, arr+n) << endl;

    // 👉 Sum
    int sum = accumulate(arr, arr+n, 0);
    cout << "Sum: " << sum << endl;

    // 👉 Search
    auto it = find(arr, arr+n, 40);
    if (it != arr+n) {
        cout << "Found 40 at index: " << (it - arr) << endl;
    } else {
        cout << "40 not found" << endl;
    }
}

int main() {
    basicOfArray();
    return 0;
}
