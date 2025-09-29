#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for C-Style Strings (char[] in C++)
// -----------------------------------------------------
// ✅ Represented as an array of characters ending with '\0' (null char)
// ✅ Fixed size (need to declare capacity beforehand)
// ✅ Not dynamic like std::string
// ✅ Functions available in <cstring> (string.h):
//    - strlen(str) → length (excluding '\0')
//    - strcpy(dest, src) → copy
//    - strncpy(dest, src, n) → copy n chars
//    - strcat(dest, src) → concatenate
//    - strcmp(a, b) → compare (0 if equal)
//    - strchr(str, ch) → first occurrence of char
//    - strstr(str, sub) → first occurrence of substring

void basicOfCharString() {
    // 👉 Initialization
    char str1[20] = "Hello";   // stored as ['H','e','l','l','o','\0']
    char str2[] = "World";
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    // 👉 Length
    cout << "Length of str1: " << strlen(str1) << endl;

    // 👉 Copy
    char copyStr[20];
    strcpy(copyStr, str1); // copy str1 → copyStr
    cout << "Copied: " << copyStr << endl;

    // 👉 Concatenate
    strcat(str1, " C++");
    cout << "Concatenated str1: " << str1 << endl;

    // 👉 Compare
    cout << "Compare(str1, str2): " << strcmp(str1, str2) << endl;
    // <0 → str1 < str2, 0 → equal, >0 → str1 > str2

    // 👉 Find character
    char* pos = strchr(str1, 'C');
    if (pos) {
        cout << "Found 'C' at index: " << (pos - str1) << endl;
    }

    // 👉 Find substring
    char* sub = strstr(str1, "C++");
    if (sub) {
        cout << "Found substring 'C++' starting at index: " << (sub - str1) << endl;
    }

    // 👉 Update character
    str1[0] = 'h';
    cout << "Modified str1: " << str1 << endl;

    // ⚠️ Danger: Overflow if copying into small array
    // char small[5];
    // strcpy(small, "TooBig"); // ❌ buffer overflow!
}

int main() {
    basicOfCharString();
    return 0;
}
