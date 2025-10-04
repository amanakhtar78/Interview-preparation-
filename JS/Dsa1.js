// //📌 Basic Level (Warm-up / Fundamentals)

//1 Print Fibonacci sequence up to n terms.
//2 Find factorial of a number (iterative and recursive).
//3 Check if a string is a palindrome.
//4 Reverse a string without using built-in reverse.
//5 Find the largest and smallest number in an array.
//6 Find the second largest element in an array.
//7 Count vowels and consonants in a string.
//8 Find the missing number in an array of 1..n.
//9 Find the duplicate elements in an array.
//10 Check if two strings are anagrams.
//11 Check if a number is prime.
//12 Generate all prime numbers up to n.

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 1. Print Fibonacci sequence up to n terms
function fibonacci(n) {
  let seq = [0, 1];
  for (let i = 2; i < n; i++) {
    seq[i] = seq[i - 1] + seq[i - 2];
  }
  return seq.slice(0, n);
}

// Example
console.log(fibonacci(10)); // [0,1,1,2,3,5,8,13,21,34]
//recursive
function fibonacciRecursive(n) {
  if (n <= 1) return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

function printFibonacci(n) {
  let result = [];
  for (let i = 0; i < n; i++) {
    result.push(fibonacciRecursive(i));
  }
  console.log(result);
}

printFibonacci(6); // [0, 1, 1, 2, 3, 5]
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 2. Factorial of a number (iterative + recursive)
// Iterative
function factorialIterative(n) {
  let result = 1;
  for (let i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Recursive
function factorialRecursive(n) {
  if (n === 0 || n === 1) return 1;
  return n * factorialRecursive(n - 1);
}

// Example
console.log(factorialIterative(5)); // 120
console.log(factorialRecursive(5)); // 120
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

////📌 3. Check if a string is a palindrome
function isPalindrome(str) {
  str = str.toLowerCase().replace(/[^a-z0-9]/g, "");
  let left = 0,
    right = str.length - 1;
  while (left < right) {
    if (str[left] !== str[right]) return false;
    left++;
    right--;
  }
  return true;
}
function palindromeShortCut(str) {
  str = str.toLowerCase();
  return str === str.split("").reverse().join("");
}

// Example
console.log(isPalindrome("Racecar")); // true
console.log(palindromeShortCut("hello")); // false

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 4. Reverse a string without using built-in reverse
function reverseString(str) {
  let result = "";
  for (let i = str.length - 1; i >= 0; i--) {
    result += str[i];
  }
  return result;
}

// Example
console.log(reverseString("hello")); // "olleh"
// 1. Using built-in methods (short & clean)
function reverseString(str) {
  return str.split("").reverse().join("");
}
// 2. Using spread syntax
function reverseString(str) {
  return [...str].reverse().join("");
}
// 3. Using reduce (functional style)
function reverseString(str) {
  return str.split("").reduce((rev, char) => char + rev, "");
}
// ⚡ But you can do it with divide and conquer (still O(n) time, but cool to see recursion):

function reverseString(str) {
  if (str.length <= 1) return str;

  const mid = Math.floor(str.length / 2);
  const left = str.slice(0, mid);
  const right = str.slice(mid);

  // reverse right + reverse left
  return reverseString(right) + reverseString(left);
}
// 🔹 In-place style (swap with two pointers)
function reverseString(str) {
  let arr = str.split("");
  let left = 0,
    right = arr.length - 1;

  while (left < right) {
    [arr[left], arr[right]] = [arr[right], arr[left]]; // swap
    left++;
    right--;
  }

  return arr.join("");
}
console.log(reverseString("hello")); // "olleh"

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 5. Find the largest and smallest number in an array
function findMinMax(arr) {
  let min = arr[0],
    max = arr[0];
  for (let num of arr) {
    if (num < min) min = num;
    if (num > max) max = num;
  }
  return { min, max };
}

// Example
console.log(findMinMax([3, 7, 2, 9, -1])); // { min: -1, max: 9 }

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 6. Find the second largest element in an array
function secondLargest(arr) {
  let first = -Infinity,
    second = -Infinity;
  for (let num of arr) {
    if (num > first) {
      second = first;
      first = num;
    } else if (num > second && num < first) {
      second = num;
    }
  }
  return second === -Infinity ? null : second;
}
// Example
console.log(secondLargest([10, 5, 20, 8])); // 10
// 🔹 1. Using Math.min / Math.max with spread
function findMinMax(arr) {
  return {
    min: Math.min(...arr),
    max: Math.max(...arr),
  };
}
console.log(findMinMax([3, 7, 2, 9, -1]));
// { min: -1, max: 9 }
// 🔹 3. Using sort (less efficient: O(n log n))
function findMinMax(arr) {
  const sorted = [...arr].sort((a, b) => a - b);
  return { min: sorted[0], max: sorted[sorted.length - 1] };
}
console.log(findMinMax([3, 7, 2, 9, -1]));
// { min: -1, max: 9 }
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////📌 7. Count vowels and consonants in a string
function countVowelsConsonants(str) {
  str = str.toLowerCase().replace(/[^a-z]/g, "");
  let vowels = "aeiou";
  let vCount = 0,
    cCount = 0;
  for (let ch of str) {
    if (vowels.includes(ch)) vCount++;
    else cCount++;
  }
  return { vowels: vCount, consonants: cCount };
}

// Example
console.log(countVowelsConsonants("Hello World")); // { vowels: 3, consonants: 7 }

////📌 8. Find the missing number in an array of 1..n
function findMissingNumber(arr, n) {
  let expectedSum = (n * (n + 1)) / 2;
  let actualSum = arr.reduce((a, b) => a + b, 0);
  return expectedSum - actualSum;
}

// Example
console.log(findMissingNumber([1, 2, 4, 5, 6], 6)); // 3

////📌 9. Find the duplicate elements in an array
function findDuplicates(arr) {
  let seen = new Set();
  let duplicates = new Set();
  for (let num of arr) {
    if (seen.has(num)) duplicates.add(num);
    else seen.add(num);
  }
  return [...duplicates];
}

// Example
console.log(findDuplicates([1, 2, 3, 2, 4, 5, 1])); // [2, 1]

////📌 10. Check if two strings are anagrams
function isAnagram(str1, str2) {
  str1 = str1.toLowerCase().replace(/[^a-z0-9]/g, "");
  str2 = str2.toLowerCase().replace(/[^a-z0-9]/g, "");
  if (str1.length !== str2.length) return false;
  return str1.split("").sort().join("") === str2.split("").sort().join("");
}

// Example
console.log(isAnagram("listen", "silent")); // true
console.log(isAnagram("hello", "world")); // false

////📌 11. Check if a number is prime
function isPrime(n) {
  if (n < 2) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}

// Example
console.log(isPrime(7)); // true
console.log(isPrime(12)); // false

////📌 12. Generate all prime numbers up to n
function generatePrimes(n) {
  let primes = [];
  for (let i = 2; i <= n; i++) {
    if (isPrime(i)) primes.push(i);
  }
  return primes;
}

function isPrime(num) {
  if (num < 2) return false;
  for (let i = 2; i * i <= num; i++) {
    if (num % i === 0) return false;
  }
  return true;
}

// Example
console.log(generatePrimes(30)); // [2,3,5,7,11,13,17,19,23,29]
