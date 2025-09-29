#include <bits/stdc++.h>
using namespace std;

// Covered Algorithms:

// sort, stable_sort, min, max, minmax
// accumulate, count, find
// binary_search, lower_bound, upper_bound
// next_permutation, prev_permutation
// reverse, rotate, unique
// remove, replace
// max_element, min_element
// all_of, any_of, none_of

int main() {
    // ------------------------------------------------------
    // 1. sort() → ascending / descending
    // ------------------------------------------------------
    vector<int> v1 = {4, 1, 3, 2};
    sort(v1.begin(), v1.end()); 
    // ascending
    // Expected: 1 2 3 4
    cout << "sort ascending: ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    sort(v1.begin(), v1.end(), greater<int>());
    // descending
    // Expected: 4 3 2 1
    cout << "sort descending: ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    // ------------------------------------------------------
    // 2. stable_sort() → preserves relative order
    // ------------------------------------------------------
    vector<pair<int,char>> v2 = {{2,'a'},{1,'b'},{2,'c'},{1,'d'}};
    stable_sort(v2.begin(), v2.end(), [](auto &a, auto &b){return a.first < b.first;});
    // Expected: (1,'b') (1,'d') (2,'a') (2,'c')
    cout << "stable_sort: ";
    for (auto &p : v2) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // ------------------------------------------------------
    // 3. min(), max(), minmax()
    // ------------------------------------------------------
    cout << "min(10,20): " << min(10,20) << endl;  // 10
    cout << "max(10,20): " << max(10,20) << endl;  // 20
    auto mm = minmax({3,7,1,9});
    // Expected: min=1, max=9
    cout << "minmax -> min:" << *mm.first << " max:" << *mm.second << endl;

    // ------------------------------------------------------
    // 4. accumulate() → sum or custom reduce
    // ------------------------------------------------------
    vector<int> v3 = {1,2,3,4,5};
    int sum = accumulate(v3.begin(), v3.end(), 0);
    // Expected: 15
    cout << "accumulate sum: " << sum << endl;

    int product = accumulate(v3.begin(), v3.end(), 1, multiplies<int>());
    // Expected: 120
    cout << "accumulate product: " << product << endl;

    // ------------------------------------------------------
    // 5. count() → frequency of element
    // ------------------------------------------------------
    vector<int> v4 = {1,2,2,3,2,4};
    cout << "count of 2: " << count(v4.begin(), v4.end(), 2) << endl; // 3

    // ------------------------------------------------------
    // 6. find() → iterator to element or end()
    // ------------------------------------------------------
    auto it = find(v4.begin(), v4.end(), 3);
    if (it != v4.end()) cout << "Found 3 at index: " << it - v4.begin() << endl; // 3rd index

    // ------------------------------------------------------
    // 7. binary_search() → works on sorted data
    // ------------------------------------------------------
    vector<int> v5 = {1,2,3,4,5};
    cout << "binary_search 3: " << binary_search(v5.begin(), v5.end(), 3) << endl; // 1 (true)
    cout << "binary_search 9: " << binary_search(v5.begin(), v5.end(), 9) << endl; // 0 (false)

    // ------------------------------------------------------
    // 8. lower_bound(), upper_bound()
    // ------------------------------------------------------
    vector<int> v6 = {1,2,2,2,3,4};
    cout << "lower_bound(2): " << (lower_bound(v6.begin(), v6.end(), 2) - v6.begin()) << endl; // 1
    cout << "upper_bound(2): " << (upper_bound(v6.begin(), v6.end(), 2) - v6.begin()) << endl; // 4

    // ------------------------------------------------------
    // 9. next_permutation(), prev_permutation()
    // ------------------------------------------------------
    vector<int> v7 = {1,2,3};
    next_permutation(v7.begin(), v7.end());
    // Expected: 1 3 2
    cout << "next_permutation: ";
    for (int x : v7) cout << x << " ";
    cout << endl;

    prev_permutation(v7.begin(), v7.end());
    // Expected: 1 2 3 (back to original)
    cout << "prev_permutation: ";
    for (int x : v7) cout << x << " ";
    cout << endl;

    // ------------------------------------------------------
    // 10. reverse()
    // ------------------------------------------------------
    vector<int> v8 = {1,2,3,4};
    reverse(v8.begin(), v8.end());
    // Expected: 4 3 2 1
    cout << "reverse: ";
    for (int x : v8) cout << x << " ";
    cout << endl;

    // ------------------------------------------------------
    // 11. rotate()
    // ------------------------------------------------------
    vector<int> v9 = {1,2,3,4,5};
    rotate(v9.begin(), v9.begin()+2, v9.end());
    // Expected: 3 4 5 1 2
    cout << "rotate: ";
    for (int x : v9) cout << x << " ";
    cout << endl;

    // ------------------------------------------------------
    // 12. unique() → removes consecutive duplicates
    // ------------------------------------------------------
    vector<int> v10 = {1,1,2,2,3,1};
    auto newEnd = unique(v10.begin(), v10.end());
    // Expected: 1 2 3 1
    cout << "unique: ";
    for (auto it = v10.begin(); it != newEnd; it++) cout << *it << " ";
    cout << endl;

    // ------------------------------------------------------
    // 13. remove(), remove_if()
    // ------------------------------------------------------
    vector<int> v11 = {1,2,3,2,4};
    auto newEnd2 = remove(v11.begin(), v11.end(), 2);
    // Expected sequence: 1 3 4
    cout << "remove 2: ";
    for (auto it = v11.begin(); it != newEnd2; it++) cout << *it << " ";
    cout << endl;

    // ------------------------------------------------------
    // 14. replace(), replace_if()
    // ------------------------------------------------------
    vector<int> v12 = {1,2,2,3};
    replace(v12.begin(), v12.end(), 2, 9);
    // Expected: 1 9 9 3
    cout << "replace 2->9: ";
    for (int x : v12) cout << x << " ";
    cout << endl;

    // ------------------------------------------------------
    // 15. max_element(), min_element()
    // ------------------------------------------------------
    vector<int> v13 = {10,20,5,40};
    cout << "max_element: " << *max_element(v13.begin(), v13.end()) << endl; // 40
    cout << "min_element: " << d*min_element(v13.begin(), v13.end()) << endl; // 5

    // ------------------------------------------------------
    // 16. all_of(), any_of(), none_of()
    // ------------------------------------------------------
    vector<int> v14 = {2,4,6};
    cout << "all_of even: " << all_of(v14.begin(), v14.end(), [](int x){return x%2==0;}) << endl; // 1
    cout << "any_of >5: " << any_of(v14.begin(), v14.end(), [](int x){return x>5;}) << endl; // 1
    cout << "none_of <0: " << none_of(v14.begin(), v14.end(), [](int x){return x<0;}) << endl; // 1

    return 0;
}
