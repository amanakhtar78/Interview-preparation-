#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for String (C++)
// -----------------------------------------
// ✅ std::string is dynamic (resizable) unlike char[]
// ✅ Stores sequence of characters
// ✅ Supports indexing, concatenation, comparison, substring, etc.
// ✅ Common methods:
//    - s.size(), s.length() → length
//    - s.empty() → check if empty
//    - s.push_back(ch), s.pop_back()
//    - s.append(str), s += str
//    - s.substr(pos, len) → substring
//    - s.find(str) → index of substring (or npos)
//    - s.compare(str) → 0 if equal
//    - s.c_str() → get const char* (C-style string)
//    - reverse(s.begin(), s.end()) → reverse string

void basicOfString() {
    // 👉 Initialization
    string s1 = "Hello";
    string s2("World");
    string s3(5, '*'); // "*****"

    cout << s1 << " " << s2 << " " << s3 << endl;

    // 👉 Concatenation
    string s4 = s1 + " " + s2;
    cout << "Concatenated: " << s4 << endl;

    // 👉 Append
    s1.append(" C++");
    cout << "Append: " << s1 << endl;

    // 👉 Size / Length
    cout << "Length: " << s1.size() << endl;

    // 👉 Access characters
    cout << s1[0] << " " << s1.at(1) << endl; // H e

    // 👉 Modify
    s1[0] = 'h';
    cout << "Modified: " << s1 << endl;

    // 👉 Substring
    string sub = s1.substr(0, 5);
    cout << "Substring: " << sub << endl;

    // 👉 Find
    size_t pos = s1.find("C++");
    if (pos != string::npos)
        cout << "Found at index: " << pos << endl;

    // 👉 Compare
    cout << (s1.compare(s2) == 0 ? "Equal" : "Not equal") << endl;

    // 👉 Iterate
    cout << "Chars: ";
    for (char c : s1) cout << c << " ";
    cout << endl;

    // 👉 Reverse
    reverse(s1.begin(), s1.end());
    cout << "Reversed: " << s1 << endl;

    // 👉 Clear
    s1.clear();
    cout << "Is empty? " << (s1.empty() ? "Yes" : "No") << endl;
}

int main() {
    basicOfString();
    return 0;
}
