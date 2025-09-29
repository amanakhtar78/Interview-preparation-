// 📌 String Manipulation
//21 Longest common prefix from array of strings.
//22 First non-repeating character in a string.
//23 Longest palindrome substring.
//24 Valid parentheses check using stack.
//25 Count occurrences of a word in a string.

// 📌 Searching & Sorting
//26 Binary Search (iterative + recursive).
//27 Implement Bubble Sort / Selection Sort / Insertion Sort.
//28 Merge Sort.
//29 Quick Sort.
//30 Search in rotated sorted array.

// 📌 String Manipulation
// 21. Longest common prefix from array of strings
function longestCommonPrefix(strs) {
  if (!strs.length) return "";
  let prefix = strs[0];
  for (let i = 1; i < strs.length; i++) {
    while (strs[i].indexOf(prefix) !== 0) {
      prefix = prefix.slice(0, prefix.length - 1);
      if (!prefix) return "";
    }
  }
  return prefix;
}

// Example
console.log(longestCommonPrefix(["flower", "flow", "flight"])); // "fl"

// 22. First non-repeating character in a string
function firstNonRepeatingChar(str) {
  let map = {};
  for (let ch of str) {
    map[ch] = (map[ch] || 0) + 1;
  }
  for (let i = 0; i < str.length; i++) {
    if (map[str[i]] === 1) return str[i];
  }
  return null;
}

// Example
console.log(firstNonRepeatingChar("swiss")); // "w"

// 23. Longest palindrome substring
function longestPalindrome(s) {
  if (s.length < 2) return s;
  let start = 0,
    maxLen = 1;

  function expandAroundCenter(left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      if (right - left + 1 > maxLen) {
        start = left;
        maxLen = right - left + 1;
      }
      left--;
      right++;
    }
  }

  for (let i = 0; i < s.length; i++) {
    expandAroundCenter(i, i); // odd length
    expandAroundCenter(i, i + 1); // even length
  }

  return s.substring(start, start + maxLen);
}

// Example
console.log(longestPalindrome("babad")); // "bab" or "aba"

// 24. Valid parentheses check using stack
function isValidParentheses(s) {
  let stack = [];
  let map = { ")": "(", "]": "[", "}": "{" };

  for (let ch of s) {
    if (ch === "(" || ch === "[" || ch === "{") {
      stack.push(ch);
    } else {
      if (stack.pop() !== map[ch]) return false;
    }
  }
  return stack.length === 0;
}

// Example
console.log(isValidParentheses("()[]{}")); // true
console.log(isValidParentheses("(]")); // false

// 25. Count occurrences of a word in a string
function countWordOccurrences(str, word) {
  let words = str.toLowerCase().split(/\s+/);
  let count = 0;
  for (let w of words) {
    if (w === word.toLowerCase()) count++;
  }
  return count;
}

// Example
console.log(countWordOccurrences("The cat and the dog chased the cat", "cat")); // 2

// 📌 Searching & Sorting
// 26. Binary Search (iterative + recursive)
// Iterative
function binarySearchIterative(arr, target) {
  let left = 0,
    right = arr.length - 1;
  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    if (arr[mid] === target) return mid;
    if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

// Recursive
function binarySearchRecursive(arr, target, left = 0, right = arr.length - 1) {
  if (left > right) return -1;
  let mid = Math.floor((left + right) / 2);
  if (arr[mid] === target) return mid;
  if (arr[mid] < target)
    return binarySearchRecursive(arr, target, mid + 1, right);
  return binarySearchRecursive(arr, target, left, mid - 1);
}

// Example
console.log(binarySearchIterative([1, 2, 3, 4, 5, 6], 4)); // 3
console.log(binarySearchRecursive([1, 2, 3, 4, 5, 6], 4)); // 3

// 27. Bubble Sort / Selection Sort / Insertion Sort
// Bubble Sort
function bubbleSort(arr) {
  let n = arr.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
    }
  }
  return arr;
}

// Selection Sort
function selectionSort(arr) {
  let n = arr.length;
  for (let i = 0; i < n; i++) {
    let minIdx = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx]) minIdx = j;
    }
    [arr[i], arr[minIdx]] = [arr[minIdx], arr[i]];
  }
  return arr;
}

// Insertion Sort
function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  return arr;
}

// Example
console.log(bubbleSort([5, 3, 8, 4, 2])); // [2,3,4,5,8]
console.log(selectionSort([5, 3, 8, 4, 2])); // [2,3,4,5,8]
console.log(insertionSort([5, 3, 8, 4, 2])); // [2,3,4,5,8]

// 28. Merge Sort
function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  let mid = Math.floor(arr.length / 2);
  let left = mergeSort(arr.slice(0, mid));
  let right = mergeSort(arr.slice(mid));

  return merge(left, right);
}

function merge(left, right) {
  let result = [];
  let i = 0,
    j = 0;
  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) result.push(left[i++]);
    else result.push(right[j++]);
  }
  return [...result, ...left.slice(i), ...right.slice(j)];
}

// Example
console.log(mergeSort([38, 27, 43, 3, 9, 82, 10])); // [3,9,10,27,38,43,82]

// 29. Quick Sort
function quickSort(arr) {
  if (arr.length <= 1) return arr;
  let pivot = arr[arr.length - 1];
  let left = [],
    right = [];
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i] < pivot) left.push(arr[i]);
    else right.push(arr[i]);
  }
  return [...quickSort(left), pivot, ...quickSort(right)];
}

// Example
console.log(quickSort([10, 7, 8, 9, 1, 5])); // [1,5,7,8,9,10]

// 30. Search in rotated sorted array
function searchRotatedArray(nums, target) {
  let left = 0,
    right = nums.length - 1;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    if (nums[mid] === target) return mid;

    // left half sorted
    if (nums[left] <= nums[mid]) {
      if (target >= nums[left] && target < nums[mid]) right = mid - 1;
      else left = mid + 1;
    }
    // right half sorted
    else {
      if (target > nums[mid] && target <= nums[right]) left = mid + 1;
      else right = mid - 1;
    }
  }

  return -1;
}

// Example
console.log(searchRotatedArray([4, 5, 6, 7, 0, 1, 2], 0)); // 4
console.log(searchRotatedArray([4, 5, 6, 7, 0, 1, 2], 3)); // -1
