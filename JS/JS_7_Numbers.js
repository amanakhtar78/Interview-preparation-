// 🎯 LEARNING NOTES for Numbers in JavaScript
// -----------------------------------------
// ✅ JS has only ONE numeric type: "number" (IEEE 754 double precision)
//    - Can represent integers and floats
//    - Special values: NaN, Infinity, -Infinity
// ✅ BigInt → for very large integers beyond 2^53 - 1
// ✅ Common Number methods/properties:
//    Number.MAX_VALUE, Number.MIN_VALUE
//    Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER
//    Number.isInteger(), Number.isNaN(), Number.isFinite()
// ✅ Math object → provides math utilities
//    Math.abs(x), Math.pow(x,y), Math.sqrt(x), Math.cbrt(x)
//    Math.floor(), Math.ceil(), Math.round(), Math.trunc()
//    Math.max(...arr), Math.min(...arr)
//    Math.random() → [0,1)
//    Math.sin(), Math.cos(), Math.tan()
//    Math.log(), Math.log10(), Math.exp()
// ✅ toFixed(), toPrecision() → formatting numbers

// 👉 Basic usage
let a = 10; // integer
let b = 3.14; // float
let c = 1e12; // exponential
let d = NaN; // Not a Number
let e = Infinity; // infinity
let big = 123456789012345678901234567890n; // BigInt

console.log("a:", a, "b:", b, "c:", c, "d:", d, "e:", e, "big:", big);

// 👉 Arithmetic
console.log("a + 5 =", a + 5);
console.log("a * 2 =", a * 2);
console.log("b / 2 =", b / 2);
console.log("a % 3 =", a % 3);
console.log("2 ** 5 =", 2 ** 5); // exponentiation

// 👉 Math functions
console.log("Math.abs(-10) =", Math.abs(-10));
console.log("Math.pow(2, 5) =", Math.pow(2, 5));
console.log("Math.sqrt(16) =", Math.sqrt(16));
console.log("Math.cbrt(27) =", Math.cbrt(27));
console.log("Math.max(3, 7) =", Math.max(3, 7));
console.log("Math.min(3, 7) =", Math.min(3, 7));

// 👉 Rounding
console.log("Math.floor(3.9) =", Math.floor(3.9));
console.log("Math.ceil(3.1) =", Math.ceil(3.1));
console.log("Math.round(3.5) =", Math.round(3.5));
console.log("Math.trunc(3.9) =", Math.trunc(3.9));

// 👉 Random
console.log("Math.random() =", Math.random()); // random between [0,1)

// 👉 Logarithms / Exponent
console.log("Math.log(Math.E) =", Math.log(Math.E)); // natural log
console.log("Math.log10(100) =", Math.log10(100)); // base-10 log
console.log("Math.exp(1) =", Math.exp(1)); // e^1

// 👉 Trigonometry
console.log("Math.sin(0) =", Math.sin(0));
console.log("Math.cos(0) =", Math.cos(0));
console.log("Math.tan(0) =", Math.tan(0));

// 👉 Number properties
console.log("MAX_VALUE =", Number.MAX_VALUE);
console.log("MIN_VALUE =", Number.MIN_VALUE);
console.log("MAX_SAFE_INTEGER =", Number.MAX_SAFE_INTEGER);
console.log("MIN_SAFE_INTEGER =", Number.MIN_SAFE_INTEGER);

// 👉 Checkers
console.log("Number.isInteger(10) =", Number.isInteger(10));
console.log("Number.isNaN(NaN) =", Number.isNaN(NaN));
console.log("Number.isFinite(1/0) =", Number.isFinite(1 / 0));

// 👉 Formatting
let num = 1234.5678;
console.log("toFixed(2) =", num.toFixed(2)); // "1234.57"
console.log("toPrecision(5) =", num.toPrecision(5)); // "1234.6"
