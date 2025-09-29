// ===============================
// Sorting Algorithms in JavaScript
// ===============================

// 📌 1. Built-in Sort
// Time Complexity: O(n log n) average
// Space Complexity: O(n) (depends on implementation, JS uses Timsort)
// ⚠️ Default sort is lexicographic, so for numbers use comparator
let arr1 = [5, 2, 9, 1, 5, 6];
console.log("Built-in Sort (default lexicographic):", arr1.sort()); // ["1","2","5","5","6","9"]
arr1 = [5, 2, 9, 1, 5, 6];
console.log(
  "Built-in Sort (numeric):",
  arr1.sort((a, b) => a - b)
); // [1,2,5,5,6,9]

// 📌 2. Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// In-place, very slow, used mainly for teaching
function bubbleSort(arr) {
  let n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]; // swap
      }
    }
  }
  return arr;
}
console.log("Bubble Sort:", bubbleSort([5, 2, 9, 1, 5, 6]));

// 📌 3. Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// In-place, useful when memory is very limited
function selectionSort(arr) {
  let n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }
    [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
  }
  return arr;
}
console.log("Selection Sort:", selectionSort([5, 2, 9, 1, 5, 6]));

// 📌 4. Insertion Sort
// Time Complexity: O(n^2) worst, O(n) best (already sorted)
// Space Complexity: O(1)
// Good for nearly sorted arrays
function insertionSort(arr) {
  let n = arr.length;
  for (let i = 1; i < n; i++) {
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
console.log("Insertion Sort:", insertionSort([5, 2, 9, 1, 5, 6]));

// 📌 5. Merge Sort
// Time Complexity: O(n log n) (divide & merge steps)
// Space Complexity: O(n) (extra arrays for merging)
// Stable sort, good for linked lists
function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  const mid = Math.floor(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

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
  return result.concat(left.slice(i)).concat(right.slice(j));
}

console.log("Merge Sort:", mergeSort([5, 2, 9, 1, 5, 6]));

// 📌 6. Quick Sort
// Time Complexity: O(n log n) average, O(n^2) worst (bad pivot)
// Space Complexity: O(log n) (recursive stack) or O(n) if extra arrays used
// Very fast in practice, used widely
function quickSort(arr) {
  if (arr.length <= 1) return arr;
  const pivot = arr[arr.length - 1];
  const left = [],
    right = [];

  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i] < pivot) left.push(arr[i]);
    else right.push(arr[i]);
  }

  return [...quickSort(left), pivot, ...quickSort(right)];
}

console.log("Quick Sort:", quickSort([5, 2, 9, 1, 5, 6]));
