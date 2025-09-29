#include <bits/stdc++.h>
using namespace std;

// 🎯 LEARNING NOTES for Numbers in C++
// -----------------------------------------
// ✅ Types:
//    - int, long, long long → integers
//    - float, double, long double → decimals
//    - unsigned int → only positive integers
// ✅ Common utilities (in <cmath> / <algorithm>):
//    - abs(x) → absolute value
//    - pow(x,y) → x^y
//    - sqrt(x) → square root
//    - cbrt(x) → cube root
//    - max(a,b), min(a,b)
//    - floor(x), ceil(x), round(x)
//    - log(x), log10(x), exp(x)
//    - sin, cos, tan, etc.
// ✅ Limits:
//    - INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN (in <climits>)
//    - numeric_limits<T>::max()

void basicOfNumbers() {
    // 👉 Initialization
    int a = 10;
    double b = 3.14;
    long long c = 1e12;
    unsigned int d = 42;

    cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

    // 👉 Arithmetic
    cout << "a + 5 = " << a + 5 << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "b / 2 = " << b / 2 << endl;
    cout << "a % 3 = " << a % 3 << endl;

    // 👉 Math functions
    cout << "abs(-10) = " << abs(-10) << endl;
    cout << "pow(2, 5) = " << pow(2, 5) << endl;
    cout << "sqrt(16) = " << sqrt(16) << endl;
    cout << "cbrt(27) = " << cbrt(27) << endl;
    cout << "max(3, 7) = " << max(3, 7) << endl;
    cout << "min(3, 7) = " << min(3, 7) << endl;

    // 👉 Rounding
    cout << "floor(3.9) = " << floor(3.9) << endl;
    cout << "ceil(3.1) = " << ceil(3.1) << endl;
    cout << "round(3.5) = " << round(3.5) << endl;

    // 👉 Logarithms / Exponent
    cout << "log(2.718) ≈ " << log(2.718) << endl;     // natural log
    cout << "log10(100) = " << log10(100) << endl;     // base-10 log
    cout << "exp(1) = " << exp(1) << endl;             // e^1

    // 👉 Trigonometry
    cout << "sin(0) = " << sin(0) << endl;
    cout << "cos(0) = " << cos(0) << endl;
    cout << "tan(0) = " << tan(0) << endl;

    // 👉 Limits
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "INT_MIN = " << INT_MIN << endl;
    cout << "LLONG_MAX = " << LLONG_MAX << endl;
    cout << "LLONG_MIN = " << LLONG_MIN << endl;
    cout << "double max = " << numeric_limits<double>::max() << endl;
}

int main() {
    basicOfNumbers();
    return 0;
}
