// 🎯 LEARNING NOTES for Set (JavaScript)
// --------------------------------------
// ✅ Collection of UNIQUE values (no duplicates allowed)
// ✅ Values can be any type (string, number, object, etc.)
// ✅ Maintains insertion order
// ✅ Common utilities:
//    - set.add(value) → add value
//    - set.has(value) → check existence
//    - set.delete(value) → remove value
//    - set.size → number of values
//    - set.clear() → remove all values
// ✅ Iteration methods:
//    - set.keys() → same as values() (for compatibility with Map)
//    - set.values() → iterator of values
//    - set.entries() → [value, value] pairs (for compatibility with Map)
//    - set.forEach(val => {}) → loop over values

function basicOfSet() {
  // 👉 Initialization
  let set = new Set([1, 2, 3, 3, 4, 5]); // duplicate "3" ignored
  console.log(set);
  // Set(5) { 1, 2, 3, 4, 5 }

  // 👉 Add values
  set.add(6);
  set.add(2); // ignored (already exists)
  console.log(set);
  // Set(6) { 1, 2, 3, 4, 5, 6 }

  // 👉 Check existence
  console.log(set.has(3)); // true
  console.log(set.has(10)); // false

  // 👉 Delete
  set.delete(4);
  console.log(set);
  // Set(5) { 1, 2, 3, 5, 6 }

  // 👉 Size
  console.log(set.size); // 5

  // 👉 Iteration
  for (let val of set) {
    console.log(val);
  }
  // 1, 2, 3, 5, 6

  // 👉 forEach
  set.forEach((v) => console.log("Value:", v));
  // Value: 1 ...

  // 👉 Keys / Values / Entries
  console.log([...set.keys()]); // [1, 2, 3, 5, 6]
  console.log([...set.values()]); // [1, 2, 3, 5, 6]
  console.log([...set.entries()]);
  // [ [1,1], [2,2], [3,3], [5,5], [6,6] ]

  // 👉 Convert Set → Array
  let arr = [...set];
  console.log(arr); // [1, 2, 3, 5, 6]

  // 👉 Use case: remove duplicates from array
  let nums = [1, 2, 2, 3, 4, 4, 5];
  let unique = [...new Set(nums)];
  console.log(unique); // [1, 2, 3, 4, 5]
}

basicOfSet();
